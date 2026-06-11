#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double distance(long double x1, long double y1, long double x2, long double y2);

int main () {
    // input
    long double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // solve
    long double d;
    d = distance(x1, y1, x2, y2);

    // output
    cout << fixed;
    cout << setprecision(5) << d << endl;
}

long double distance(long double x1, long double y1, long double x2, long double y2) {
    long double d;
    d = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    return d;
}
