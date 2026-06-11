#include<stdio.h>
#include<math.h>
int main(){
  int i,n;
  double s,a,sum,powsum,ave;
  while(1){
    sum=0.0,powsum=0.0;
    scanf("%d",&n);
    if(n==0)break;
    for(i=0;i<n;i++){
      scanf("%lf",&s);
      sum+=s;
      powsum+=s*s;
    }
    ave=sum/(double)n;
    a=pow((powsum/(double)n-ave*ave),0.5);
    printf("%f\n",a);
  }
  return 0;
}