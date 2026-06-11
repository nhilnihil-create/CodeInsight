#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

#define DEG2RAD(deg) deg * M_PI / 180

int main()
{
    int a, b, c;
    double s, l, h;

    cin >> a >> b >> c;

    s = 0.5 * a * b * sin(DEG2RAD((double)c));
    l = a + b + sqrt(a * a + b * b - 2 * a * b * cos(DEG2RAD((double)c)));
    h = b * sin(DEG2RAD((double)c));

    cout << fixed << setprecision(8) << s << endl;
    cout << fixed << setprecision(8) << l << endl;
    cout << fixed << setprecision(8) << h << endl;

    return 0;
}