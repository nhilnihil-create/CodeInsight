#include <iostream>
#include <cmath>

#define PI 3.14159265359

using namespace std;

int main(void)
{
    double a, b, c, h, r, s;
    cin >> a >> b >> r;
    s = a * b * sin(PI * r / 180) / 2;
    c = sqrt(a * a + b * b - 2 * a * b * cos(PI * r / 180));
    h = 2 * s / a;
    printf("%f\n%f\n%f\n", s, a + b + c, h);
    return 0;
}