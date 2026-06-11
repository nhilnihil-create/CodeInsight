#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(void){
    double a, b, C, S, L, h;
    scanf("%lf%lf%lf", &a, &b, &C);
    double radian = acos(-1) * C / 180;
    S = a * b * sin(radian) / 2;
    double c = sqrt(a*a + b*b - 2*a*b*cos(radian));
    L = a + b + c;
    h = sin(radian) * b;
    printf("%f\n%f\n%f\n", S, L, h);
    return 0;
}