#include <iostream>
#include <utility>

#define _USE_MATH_DEFINES   // required or compile error
#include <cmath>
#include <cstdio>


using namespace std;

int main(void) {

    double r;
    cin >> r;

    printf("%lf %lf\n", (r * r * M_PI), (r * 2 * M_PI));

    return 0;
}