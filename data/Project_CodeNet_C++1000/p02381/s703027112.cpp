#include <stdio.h>
#include <math.h>

int main(){


int s[1001];
 long long n,sum=0,i;
 double ave=0,ans2,ans1;

 for(;;){

  scanf("%lld",&n);

  if(n==0){
    break;
  }

for(i=1;i<=n;i++){

  scanf("%d",&s[i]);

  sum+=s[i];
 }

ave=(double)sum/n;

for(i=1;i<=n;i++){

  ans1 += ( s[i] - ave) * (s[i] - ave);


 }

ans2 =sqrt(ans1/n);

printf("%lf\n",ans2);

 sum=0;
 ave=0;
 ans1=0;
 ans2=0;

 }
return 0;
}
 