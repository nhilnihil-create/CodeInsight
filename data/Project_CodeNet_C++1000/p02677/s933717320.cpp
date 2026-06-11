#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    constexpr double pi = 3.1415926535;

    cout << fixed << setprecision(9);
    int a, b; cin >> a >> b;
    int h, m; cin >> h >> m;

    double ha = (h * 1800 + m * 30) / 60.0;
    double ma = (m * 360) / 60.0;
    double wa = ha - ma;

    cout << sqrt(pow(a - b * cos(wa / 180 * pi), 2) + pow(b * sin(wa / 180 * pi), 2)) << endl;
}

