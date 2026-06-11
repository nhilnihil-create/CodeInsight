#include<stdio.h>
#include<string.h>
int main(void)
{
   int sum;
   char str[1100];
   int i;
   for(i=0;i<1100;i++){
      str[i]=0;
   }
   while(1){
      scanf("%s",str);
      if(strcmp(str,"0")==0){
         break;
      }
      sum=0;
      for(i=0;str[i]!='\0';i++){
         sum+=str[i]-'0';
      }
      printf("%d\n",sum);
   }
   return 0;
}