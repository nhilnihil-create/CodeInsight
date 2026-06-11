#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double a, b, x;
    cin >> a >> b >> x;
    cout << fixed;
    cout << setprecision(6);
    if (x > a*a*b/2.0) {
        cout << atan(2.0*(a*a*b-x)/(a*a*a)) * 180 / M_PI << endl;
    } else {
        cout << atan(a*b*b/(2*x)) * 180 / M_PI << endl;
    }
}