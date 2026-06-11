#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(void){
    double a, b, deg;
    cin >> a >> b >> deg;
    double rad = M_PI * deg / 180;
    double h = b * sin(rad);
    double S = 0.5 * h * a;
    double c = sqrt(a * a + b * b - 2 * a * b * cos(rad));
    double L = a + b + c;
    printf("%f\n%f\n%f\n", S, L, h);
}