#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

#define PI 3.14159265358979323846264338327950L

// 絶対値を求める
double Abs(const double a) {
    return a > 0 ? a : -a;
}
// 二つの値の最小値を求める関数
Int Min(const Int a, const Int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}
// 二つの値の最小値を求める関数
double Min(const double a, const double b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    Int a, b, h, m;
    cin >> a >> b >> h >> m;
    Int minutes = 60 * h + m;
    double a_angle = 0.5 * (double)minutes;
    double b_angle = (double)((6 * minutes) % 360);
    double angle = Abs(a_angle - b_angle);
    angle = (double)Min(angle, 360.0f - angle) * PI / 180.0f;
    double c = sqrt((double)(a * a + b * b)  - (double)(2 * a * b) * cosl(angle));
    cout << fixed << setprecision(20) << c << endl;
    return 0;
}

