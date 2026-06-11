#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    c *= (M_PI/180);
    printf("%.10lf\n", (1.0/2.0)*a*b*sin(c));
    printf("%.10lf\n", a+b+sqrt(a*a+b*b-2*a*b*cos(c)));
    printf("%.10lf\n", b*sin(c));
    return 0;
}
