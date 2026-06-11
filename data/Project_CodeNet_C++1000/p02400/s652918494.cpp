#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    double r, a, l;
    cin >> r;
    a = r * r * M_PI;
    l = 2 * r * M_PI;
    printf("%.6f %.6f\n", a, l);
    return 0;
}