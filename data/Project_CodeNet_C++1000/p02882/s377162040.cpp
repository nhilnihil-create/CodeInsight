#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define pi acos(-1)
#define double long double

using namespace std;

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    if (x / (a * a) == b) {
        cout << "0";
        return 0;
    }
    double determinant = (2 * x) / (a * a) - b;
    if (determinant <= 0) {
        double theta = atan((2 * x) / (a * b * b)) * 180 / pi;
        cout << setprecision(12) << 90 - theta;
        return 0;
    }
    else {
        double theta = atan(-(a / (determinant - b))) * 180 / pi;
        cout << setprecision(12) << 90 - theta;
        return 0;
    }
}