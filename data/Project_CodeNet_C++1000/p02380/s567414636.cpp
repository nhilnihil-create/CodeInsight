#define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    double C;
    scanf("%d %d %lf", &a, &b, &C);
    C *= M_PI/180;

    double S=0.5*a*b*sin(C);
    double L=a+b+sqrt(a*a+b*b-2*a*b*cos(C));
    double h=b*sin(C);

    printf("%.12f\n", S);
    printf("%.12f\n", L);
    printf("%.12f\n", h);
    return 0;
}