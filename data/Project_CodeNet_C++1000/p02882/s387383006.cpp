#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long
#define PI 3.14159265358979323846

using namespace std;
int main() {
    double a, b, x; std::cin >> a >> b >> x;
    double s = x / a;
    double ans = 0;
    double a2 = 0;
    if (s == a * b) {
        ans = 0;
    }
    else {
        if (s > b * a / 2) {
            double bu = 2 * s / a - b;
            s -= a * bu;
            b -= bu;
            a2 = 2 * s / b;
        }
        else {
            a2 = 2 * s / b;
        }
        double r = std::atan(b / a2);
        // ラジアン-角度変換
        ans = r * (180.0 / PI);
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}