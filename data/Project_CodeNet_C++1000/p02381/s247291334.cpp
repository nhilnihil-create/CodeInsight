#include <stdio.h>
#include <math.h>

int main(){
  int n;
  double s[1000],sum,ave,bunsan,hensa;
  int i;

  while(1){
    scanf("%d",&n);
    if(n==0) break;
    sum=0;
    ave=0;
    bunsan=0;
    hensa=0;

    for(i=0; i<n; ++i){
      scanf("%lf",&s[i]);
      sum+=s[i];
    }

    ave=sum/n;

    for(i=0; i<n; ++i){
      bunsan+=pow(s[i]-ave,2);
    }

    bunsan/=n;

    hensa=sqrt(bunsan);

    printf("%f\n",hensa);
    
  }


  return 0;
}

