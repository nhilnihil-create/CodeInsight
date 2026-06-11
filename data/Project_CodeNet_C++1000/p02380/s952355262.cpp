#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b, C;
    cin >> a >> b >> C;

    double S = (a * b * sin(M_PI * C / 180.0)) / 2.0;
    double L = sqrt(a * a + b * b - 2 * a * b * cos(M_PI * C / 180.0)) + a + b;
    double h = 2.0 * S / a;
    cout << fixed << setprecision(8) << S << endl << L << endl << h << endl;

    return 0;
}
