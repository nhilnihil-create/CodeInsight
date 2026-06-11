#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    double rad = c * M_PI / 180;

    cout << fixed;
    cout << setprecision(8);

    cout << a * b * sin(rad) / 2 << endl;
    cout << a + b + sqrt(pow(a,2) + pow(b,2) - 2 * a * b * cos(rad)) << endl;
    cout << b * sin(rad) << endl;

    return 0;
}