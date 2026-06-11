#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double a, b, C;
    cin >> a >> b >> C;
    C = C  * M_PI / 180;

    double L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C));
    double S = a * b * sin(C) / 2;
    double h = b * sin(C);

    printf("%.6f\n%.6f\n%.6f\n", S, L, h);

    return 0;
}