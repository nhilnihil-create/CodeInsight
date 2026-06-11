#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double rad2deg(double rad) {
    return rad * 360.0 / (2.0 * M_PI);
};

int main() {

    int a, b, x;
    cin >> a >> b >> x;

    if (x == (a * a * b)) {
        cout << 0 << endl;
        return 0;
    }

    double theta;
//    if (a <= b) {
//        int v45_mul2;
//        v45_mul2 = a * a * a;

//        // theta <= 45
//        if ((2 * x) >= v45_mul2) {
//            double rhs = (2.0 * (a * a * b - x)) / (1.0 * a * a * a);
//            theta = rad2deg(atan(rhs));
//        }
//        else {
//            double rhs = (1.0 * a * b * b) / (2.0 * x);
//            theta = rad2deg(atan(rhs));
//        }
//    }
//    else {
    if (true) {
        int v = a * a * b;
        // x >= v/2
        if ((2 * x) >= v) {
            double rhs = (2.0 * (a * a * b - x)) / (1.0 * a * a * a);
            theta = rad2deg(atan(rhs));
        }
        else {
            double rhs = (1.0 * a * b * b) / (2.0 * x);
            theta = rad2deg(atan(rhs));
        }
    }

    //cout << fixed << setprecision(15);
    cout << setprecision(15);
    cout << theta << endl;
}
