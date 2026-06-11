#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PI 3.1415926535

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    double theta;
    if (x > a * a * b / 2) {
        double air = a * a * b - x;
        air /= a;
        theta = atan(2 * air / (a * a));
    } else {
        x /= a;
        theta = atan(b * b / (2 * x));
    }

    printf("%1.8f\n", theta * 180 / PI);

    return 0;
}
