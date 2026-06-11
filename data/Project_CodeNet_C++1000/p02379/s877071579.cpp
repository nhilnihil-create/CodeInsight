#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double P1[2], P2[2], x, y;

    cin >> P1[0] >> P1[1];
    cin >> P2[0] >> P2[1];
    x = P1[0]-P2[0];
    y = P1[1]-P2[1];
    cout << fixed;
    cout.precision(5);
    cout << sqrt(x*x + y*y) << endl;

    return 0;
}