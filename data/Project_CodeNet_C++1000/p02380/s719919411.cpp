#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = 4 * atan(1.0);

int
main(int argc, const char *argv[])
{
    int a, b, C;
    cin >> a >> b >> C;
    double S, L, h;
    if (C == 90) {
        S = a * b / 2; 
        L = a + b + sqrt(a*a + b*b);
        h = b;
    } else if (C < 90) {
        h = b * sin(C / 180.0 * pi);
        S = a * h / 2;
        double x = b * cos(C / 180.0 * pi);
        L = a + b + sqrt(h * h + (a - x) * (a - x));
    } else {
        h = b * sin((180 - C) / 180.0 * pi);
        S = a * h / 2;
        double x = b * cos((180 - C) / 180.0 * pi);
        L = a + b + sqrt(h * h + (x + a) * (x + a));
    }
    printf("%.8lf\n%.8lf\n%.8lf\n", S, L, h);

    return 0;
}