#include <stdio.h>
#include<math.h>
int main(void){
    int n,i;
    scanf("%d",&n);
    double a[n],b[n],p1=0,p2=0,p3=0,p=0;
    for(i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%lf",&b[i]);
    }
    for(i=0;i<n;i++){
        double x;
        x=fabs(a[i]-b[i]);
        
        p1+=x;
        p2+=pow(x,2);
        p3+=pow(x,3);
        if(p<x)
        p=x;
    }
    p2=sqrt(p2);
    p3=cbrt(p3);
    printf("%lf\n%lf\n%lf\n%lf\n",p1,p2,p3,p);
  return 0;
}