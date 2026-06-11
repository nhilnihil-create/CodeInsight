#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int32_t a, b, C;
    static const double pi = atan(1) * 4;

    cin >> a >> b >> C;

    cout << fixed << setprecision(5) << a * b * sin(C * pi / 180) / 2 << endl;
    cout << fixed << setprecision(5) << a + b + sqrt(a * a + b * b - 2 * a * b * cos(C * pi / 180)) << endl;
    cout << fixed << setprecision(5) << b * sin(C * pi / 180) << endl;

    return 0;
}