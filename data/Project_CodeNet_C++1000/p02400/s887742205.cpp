#include <iostream>
#include <stdio.h>
using namespace std;

#define pi  3.14159265358979323846

int main()
{
    double x, r, s, l;
    cin >> x;
    s = x*pi;
    r = x*pi - s;

    printf("%.6lf", (s+r)*x);
    l = 2*x;
    r = 2*x - l;
    printf(" %.6lf", (l+r)*pi);
}