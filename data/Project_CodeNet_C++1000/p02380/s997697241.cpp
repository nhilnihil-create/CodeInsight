#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void)
{
    double a, b, c;
    double s, l, h;
    cin >> a >> b >> c;
    s = 0.5 * a * b * sin(c / 180 * M_PI);
    l = a + b + sqrt(pow(a, 2.0) + pow(b, 2.0) - 2 * a * b * cos(c/180*M_PI));
    h = b * sin(c * M_PI / 180);
    cout << fixed << setprecision(10);
    cout << s << endl;
    cout << l << endl;
    cout << h << endl;
    return 0;
}

