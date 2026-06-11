#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, C;
    cin >> a >> b >> C;
    double rad = C * M_PI / 180;
    double h = sin(rad) * b;
    double S = a * h / 2;
    double L = a + b + (sqrt(a * a + b * b - (2 * a * b * cos(rad))));
    printf("%f\n%f\n%f\n", S, L, h);
}
