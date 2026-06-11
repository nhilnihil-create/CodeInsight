#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
double a;
cin >> a;
printf("%lf %lf\n", M_PI * a * a, 2.0 * a * M_PI);
return 0;
}