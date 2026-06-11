#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
    double r;
    cin >> r;
    const double p = acos(-1);

    cout << fixed << setprecision(6);
    cout << p * r * r << " " << 2 * p * r << endl;

    return 0;
}
