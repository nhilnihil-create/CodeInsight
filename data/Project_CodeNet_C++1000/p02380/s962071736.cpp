#include <stdio.h>
#include<math.h>
int main(void){
   double a,b,c,s,l,h;
   scanf("%lf%lf%lf",&a,&b,&c);
   c*=3.14159265358979;
   c/=180;
   s=a*b*sin(c)/2;
   l=sqrt(a*a+b*b-2*a*b*cos(c))+a+b;
   h=2*s/a;
   printf("%lf\n%lf\n%lf\n",s,l,h);
    return 0;
}