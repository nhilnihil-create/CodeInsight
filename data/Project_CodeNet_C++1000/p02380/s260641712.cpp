#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
    double a, b, c;
    double C;
    double S, L, h;
    double pi = acos(-1);
    
    cin >> a >> b >> C;
    C = pi * C / 180;
    S= a * b * sin(C) / 2;
    c = sqrt(a*a + b*b - 2*a*b*cos(C));
    L = a + b + c;
    h = S * 2 / a;
    
    printf("%lf\n", S);
    printf("%lf\n", L);
    printf("%lf\n", h);
    
    return 0;
}
