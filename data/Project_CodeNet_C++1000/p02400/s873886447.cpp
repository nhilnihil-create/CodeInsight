#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double r;

    do {
        cin >> r;
    } while (r <= 0.0 || r >= 10000.0);

    double S = M_PI * r * r;
    double l = 2.0 * M_PI * r;

    cout << fixed << setprecision(6) << S << " " << setprecision(6) << l << endl;

    return (0);
}