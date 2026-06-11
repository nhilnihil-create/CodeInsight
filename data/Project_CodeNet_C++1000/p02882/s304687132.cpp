#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int a, b, x; cin >> a >> b >> x;
    int cnt = 100, V = a * a * b, flag = 1;
    double pi = 3.14159265358979;
    double angle_min = 0.0, angle_max = 90.0;
    if (2 * x < a * a * b) flag = 0;
    while (cnt--) {
        double theta = (angle_min + angle_max) / 2.0;
        if (flag) {
            if (pow(a, 3) * tan(theta / 180.0 * pi) / 2.0 + x < V) angle_min = theta;
            else angle_max = theta;
        } else {
            if (a * b * b * tan((90.0 - theta) / 180.0 * pi) / 2.0 > x) angle_min = theta;
            else angle_max = theta; 
        }
    }
    double ans = angle_min;
    cout << fixed << setprecision(10) << ans << endl;
}