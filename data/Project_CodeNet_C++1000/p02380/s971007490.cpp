#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    double a, b, c, s, l, h;
    cin >> a >> b >> c;
    h = b * sin(c / 180.0 * M_PI);
    s = a * h / 2.0;
    l = sqrt(a * a + b * b - 2 * a * b * cos(c / 180.0 * M_PI));
    l += a + b;
    cout << fixed << s << endl << l << endl << h << endl;
    return 0;
}