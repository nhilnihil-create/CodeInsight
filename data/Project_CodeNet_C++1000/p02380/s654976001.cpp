#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    double c, s, l, h;
    cin>>a>>b>>c;
    c = c * 2 * M_PI / 360;
    s = 0.5 * a * b * sin(c);
    l = a + b + sqrt(a*a + b*b - 2*a*b*cos(c));
    h = b*sin(c);
    printf("%.5f\n%.5f\n%.5f\n", s, l, h);
    return 0;
}