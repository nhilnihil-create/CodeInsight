#include <stdio.h>
#include <math.h>
int main(){
    double a,b,t;
    scanf("%lf%lf%lf",&a,&b,&t);
    printf("%lf\n%lf\n%lf\n",(sin(t*3.14159265359/180)*a*b)/2,a+b+sqrt(a*a+b*b-2*a*b*cos(t*3.14159265359/180)),sin(t*3.14159265359/180)*b);
}