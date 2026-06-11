#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    double a,b,c,s;

    cin >> a >> b >> c;
    s=(a*b*sin(M_PI/(180/c)))/2;

    printf("%.6lf\n",s);
    printf("%.6lf\n", a+b+sqrt(a*a+b*b-2*a*b*cos(M_PI/(180/c))));
    printf("%.6lf\n", s*2/a);
    
    return 0;
}