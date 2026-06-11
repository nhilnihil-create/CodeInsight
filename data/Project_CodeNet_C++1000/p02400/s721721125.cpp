#include <math.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double r;
    cin >> r;
    printf("%.6lf ", M_PI * r * r);
    printf("%.6lf\n", 2 * M_PI * r);
    return 0;
}