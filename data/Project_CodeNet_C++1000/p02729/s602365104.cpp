#include<stdio.h>
int main(){
   int n,m;
   scanf("%d%d",&n,&m);
   int count=0;
   if(n>1){
      count=n*(n-1)/2;
   }
   if(m>1){
      count=count+m*(m-1)/2;
   }
   printf("%d",count);
   return 0;
}
