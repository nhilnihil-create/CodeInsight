#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double a,b,c,r,h,s;
    cin >> a >> b >> r;
    r = r /180.0 * M_PI;
    c = sqrt(a*a+b*b-2*a*b*cos(r));
    h = b * sin(r);
    s = a * h / 2.0;
    printf("%lf\n%lf\n%lf\n",s,a+b+c,h);
}
