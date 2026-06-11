#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    double s, l, h;

    cin >> a >> b >> c;

    s = a * b * sin((c / 180) * M_PI) / 2;
    l = a + b + sqrt(a * a + b * b - 2 * a * b * cos((c * M_PI) / 180));
    h = s * (double)2 / a;

    printf("%.8f\n%.8f\n%.8f\n", s, l, h);

    return (0);
}