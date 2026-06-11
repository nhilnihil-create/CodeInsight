#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    double S, L, h;
    double rad;
    double PI = acos(-1);

    cin >> a >> b >> c;
    rad = c * PI / 180;

    S = 0.5*a*b*sin(rad);
    L = a + b + sqrt(a*a + b*b - 2*a*b*cos(rad));
    h = b * sin(rad);
    // h = a * sin(rad);

    // cout << S << endl;
    // cout << L << endl;
    // cout << h << endl;

    printf("%lf\n%lf\n%lf\n", S, L, h);

    return 0;
}