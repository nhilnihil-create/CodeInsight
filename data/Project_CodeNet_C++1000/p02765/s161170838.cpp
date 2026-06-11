#include<stdio.h>
int main(){
   int n,r,b;
   scanf("%d%d",&n,&r);
   if(n>=10){
      b=r;
   }else{
      b=100*(10-n)+r;
   }
   printf("%d",b);
   return 0;
}
