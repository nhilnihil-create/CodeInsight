#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    double r, S, len;
    cin >> r;
    S = M_PI * r * r;
    len = 2 * M_PI * r;
    printf("%f %f\n", S, len);
    return 0;
}