#include <stdio.h>
#include <math.h>

int main(){

int a,b,c;
 double C,s,l,h,rad;

scanf("%d%d%d",&a,&b,&c);

 rad=c*3.14159265359/180;

C=sqrt(a*a+b*b-2*a*b*cos(rad));


l=a+b+C;

s=0.5*a*b*sin(rad);

h=2*s/a;

printf("%lf\n",s);
printf("%lf\n",l);
printf("%lf\n",h);

return 0;
}