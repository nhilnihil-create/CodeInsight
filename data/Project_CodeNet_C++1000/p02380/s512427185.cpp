#include <stdio.h>
#include <math.h>
double PI;

double deg2rad(double deg){
    return (deg/360)*2*PI;
}

int main()
{
    int a,b,c;
    double cr;

    PI=acos(-1);

    scanf("%d %d %d",&a,&b,&c);
    cr=deg2rad(c);
    
    printf("%f\n",(a*b*sin(cr))/2);
    printf("%f\n",a+b+sqrt(a*a+b*b-2*a*b*cos(cr)));
    printf("%f\n",b*sin(cr));
    
    return 0;
}
