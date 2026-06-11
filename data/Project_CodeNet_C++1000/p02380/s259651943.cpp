#include <iostream>
#include <cmath>
#include <cstdio>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    double S, L, h;
    S = 0.5 * a * b * sin((2*PI)*c/360);
    L = sqrt(a * a + b * b - (2 * a * b * cos((2*PI)*c/360))) + a + b;
    h = b * sin((2*PI)*c/360);
    printf("%.7f %.7f %.7f\n", S, L, h);
}
