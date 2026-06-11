#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

#define _USE_MATH_DEFINES

int main(void){
    double a, b, c;
    cin >> a >> b >> c;
    double h = b * sin(c * M_PI / 180.0);
    double s = a * h / 2;
    double l = a + b + sqrt(h*h + pow((a - b*cos(c * M_PI / 180.0)), 2));
    printf("%.8lf\n%.8lf\n%.8lf\n", s, l, h);
    
    return 0;
}