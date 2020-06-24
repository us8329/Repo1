/*Write a program that merges lines alternately from two files and writes the results to
new file. If one file has less number of lines than the other, the remaining lines from
the larger file should be simply copied into the target file.*/



#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
  
int main() 
{ 
   char file1[500],file2[500]; 
   printf("enter name of first file:");
   scanf("%s",file1);
   printf("enter name of seconf file:");
   scanf("%s",file2);
   FILE *fp1 = fopen(file1, "r"); 
   FILE *fp2 = fopen(file2, "r"); 
  
   // Open file to store the result 
   FILE *fp3 = fopen("merge.txt", "w"); 
   char c; 
  
   if (fp1 == NULL || fp2 == NULL || fp3 == NULL) 
   { 
         puts("Could not open files"); 
         exit(0); 
   } 

   int count1=0,count2=0;
   char c1,c2;
   FILE *t1,*t2;
   //first copy file 
   t1=fopen("testfile1.txt","w");
   t2=fopen("testfile2.txt","w");
    

   for (c1 = getc(fp1); c1 != EOF; c1 = getc(fp1)) 
     fputc(c1, t1);      
   
    for (c2 = getc(fp2); c2 != EOF; c2 = getc(fp2)) 
     fputc(c2, t2);
     fclose(t1);
     fclose(t2);
     fclose(fp1);
     fclose(fp2);
     fp1=fopen(file1,"r");
     fp2=fopen(file2,"r");
        
    char c3,c4;
    for(c3=getc(fp1);c3!=EOF;c3=getc(fp1))
    {
        if (c3 == '\n') // adds one to the counter everytime compiler hits a new line
            count1++;
    }
    for(c4=getc(fp2);c4!=EOF;c4=getc(fp2))
    {
        if (c4 == '\n') // same as above ofcourse 
            count2++;
    }
    fclose(fp1);
    fclose(fp2);

  // printf("%i\n",count1);
   //printf("%i\n",count2);

  fp1=fopen(file1,"r");
  fp2=fopen(file2,"r"); 
  
  char a1,a2,line1[100],line2[100];
      while ((!feof(fp1)) && (!feof(fp2))) 
             {
                //taes the first line from the first file 
                fgets(line1,100, fp1);
                if (!feof(fp1)) 
                {
                        fprintf(fp3, "%s", line1); //prints line in third file 
                }

                //takes the first line from the second file 
                fgets(line2,100, fp2);
                if (!feof(fp2))
                {
                        fprintf(fp3, "%s", line2); //same ugh 
                }

                strcpy(line1, "\0");  //nullifies the line string 
                strcpy(line2, "\0");
              }

  if (count1!=count2)
  {
       // Copies first file to third file 
   while ((c = fgetc(fp1)) != EOF) 
      fputc(c, fp3); 
  
   // Copies second file to third file  
   while ((c = fgetc(fp2)) != EOF) 
      fputc(c, fp3);

  }

  
  
     

  
  //closes file 
  
   fclose(fp1); 
   fclose(fp2); 
   fclose(fp3); 

   return 0; 
} 
