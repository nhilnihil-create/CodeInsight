#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    double a, b, C;
    cin >> a >> b >> C;
    double theta = acos(-1) * C / 180.0;
    double h = b * sin(theta);
    double s = (a * h) / 2.0;
    double c = sqrt(a*a + b*b - 2*a*b*cos(theta));
    printf("%lf\n%lf\n%lf\n", s, (a + b + c), h);
}