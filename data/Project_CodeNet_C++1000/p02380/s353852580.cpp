#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c, s, l, h, theta;
    const double pi = 3.1415926535897;
    cin >> a >> b >> c;
    theta = (c * pi) / (double)(180);
    s = a * b * sin(theta) / (double)(2);
    l = a + b + sqrt( a * a + b * b - 2 * a * b * cos(theta));
    h = 2 * s / a;
    printf("%.8f\n", s);
    printf("%.8f\n", l);
    printf("%.8f\n", h);
    return 0;
}

