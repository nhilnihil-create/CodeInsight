#include <stdio.h>
#include<math.h>
#define PI 3.14159265359 
int main(void){
    int a,b,C;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&C);
    double S,L,h,c;
    S=(a*b*sin(C*PI/180.0))/2;
    c=pow(a,2)+pow(b,2)-2*a*b*cos(C*PI/180.0);
    c=sqrt(c);
    L=a+b+c;
    h=b*sin(C*PI/180.0);
    printf("%f\n%f\n%f\n",S,L,h);
    return 0;
}
