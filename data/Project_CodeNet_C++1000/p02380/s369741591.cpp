#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, s , l , h;
    cin >> a >> b >> c;
    h=b*sin(c/180.0*M_PI);
    s=a*h/2.0;
    l=sqrt(pow(h,2.0)+pow(a-b*cos(c/180.0*M_PI),2.0))+a+b;
    printf("%5lf %5lf %5lf\n", s, l, h);
    return 0;
}