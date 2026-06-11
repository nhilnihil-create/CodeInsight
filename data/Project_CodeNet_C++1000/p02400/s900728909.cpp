#include <iostream>
#include <cstdio>
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main() {
    double r;
    cin >> r;
    double pi = M_PI;
    double l = 2 * r * pi;
    double S = r * r * pi;
    printf("%.9f %.9f", S, l);
}
