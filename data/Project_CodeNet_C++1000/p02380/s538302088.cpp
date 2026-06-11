#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    double a,b,c,s,l,h,PI;
    cin >> a >> b >> c;
    PI = acos(-1);
    c = PI*c/180;
    s = a * b * sin(c) * 0.5;
    l = a + b + sqrt( (a*a + b*b - 2*a*b*cos(c)) );
    h = b * sin(c);
    printf("%lf\n%lf\n%lf\n", s,l,h);
    return 0;
}