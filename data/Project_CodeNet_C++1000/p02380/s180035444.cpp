#include<stdio.h>
#include<math.h>
#define PI 3.1415926535
int main(){
    double a, b, c;
    double deg, rad;
    double S, L, H;
    scanf("%lf %lf %lf", &a, &b, &deg);
    rad = deg*PI/180;
    S = a*b*sin(rad)/2;
    H = b*sin(rad);
    c = sqrt(a*a + b*b - 2*a*b*cos(rad));
    L = a + b + c;
    printf("%f\n%f\n%f\n", S, L, H);
    return 0;
}