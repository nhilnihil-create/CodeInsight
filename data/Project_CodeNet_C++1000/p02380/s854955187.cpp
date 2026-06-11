
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const double kPi = 3.14159265359;

    double a, b, c;
    cin >> a >> b >> c;

    c = c * kPi / 180.0;

    double S = a * b * sin(c) / 2;
    double h = b * sin(c);
    double L = a + b + sqrt(pow(h, 2) + pow(a - b * cos(c), 2));
    cout << fixed << setprecision(5);
    cout << S << endl;
    cout << L << endl;
    cout << h << endl;

    return 0;
}