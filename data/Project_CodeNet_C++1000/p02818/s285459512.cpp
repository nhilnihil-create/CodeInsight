#include<stdio.h>
int main(){
   long long  a,b,k;
   scanf("%lld%lld%lld",&a,&b,&k);
   if(a>=k){
      a-=k;
   }else if(a+b>=k){
      k-=a;
      a=0;
      b-=k;
   }else{
      a=0;
      b=0;
   }
   printf("%lld %lld",a,b);
   return 0;
}
