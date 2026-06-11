#include<stdio.h>
int main(){
 long long n;
 scanf("%lld",&n);
 long long h[n+10];
 long long tmp=0,ans=0;
 for(long long i=0;i<n;i++){
  scanf(" %lld",&h[i]);
  if(i>0&&h[i-1]>=h[i])tmp++;
  else{
   if(ans<tmp)ans=tmp;
   tmp=0;
  }
 }
 if(ans<tmp)ans=tmp;
 printf("%lld\n",ans);
return 0;}