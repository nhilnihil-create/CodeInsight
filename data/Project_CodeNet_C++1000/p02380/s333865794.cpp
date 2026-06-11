#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    double pi =acos(-1);
    double d;
    d = c*pi/180;
    double x,y,z;
    x=a*b*sin(d)/2;
    y=a*a+b*b-2*a*b*cos(d);
    z=x*2/a;
    printf("%.8f\n", x);
    printf("%.8f\n", sqrt(y)+a+b);
    printf("%.8f\n", z);
}
