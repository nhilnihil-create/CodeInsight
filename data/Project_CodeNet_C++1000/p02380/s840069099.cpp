#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main(){
    int a,b,c;
    double s,l,h;
    scanf("%d %d %d",&a,&b,&c);
    s = a*b*sin(c*PI/180)/2;
    l = sqrt(a*a+b*b-2*a*b*cos(c*PI/180))+a+b;
    h = b*sin(c*PI/180);
    printf("%f %f %f\n",s,l,h);
}