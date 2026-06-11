#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    double a, b, C;
    cin >> a >> b >> C;

    double rad = C * M_PI / 180.0;

    double h = b * sin(rad);
    double S = a * h / 2.0;
    double L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad));
    cout << fixed << setprecision(7) << S << endl;
    cout << fixed << setprecision(7) << L << endl;
    cout << fixed << setprecision(7) << h << endl;

    return 0;
}