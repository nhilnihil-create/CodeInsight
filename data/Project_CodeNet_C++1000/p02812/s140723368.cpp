#include<stdio.h>
int main(){
   int n,count=0;
   scanf("%d",&n);
   char s[n];
   scanf("%s",s);
   int i;
   for(i=0;i<n;i++){
      if(i<n-2){
         if(s[i]=='A'){
            if(s[i+1]=='B'){
               if(s[i+2]=='C'){
                  count++;
               }
            }
         }
      }
   }
   printf("%d",count);
   return 0;
}
