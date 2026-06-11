#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#define PI 3.14159265358979323846264338327950L

int main(void)
{
    long double a, b, h, m; cin >> a >> b >> h >> m;
    long double t = 60 * h + m;
    long double pi = PI;
    long double theta = m / 30.0 * pi - t / 360.0 * pi;

    long double c = sqrt(a*a + b*b - 2*a*b*cos(theta));
    cout << fixed << setprecision(20) << c << endl;
}