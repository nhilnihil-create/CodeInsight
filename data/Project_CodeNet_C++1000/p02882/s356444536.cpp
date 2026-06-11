#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    double a, b, x;
    cin >> a >> b >> x;

    double ans;

    ans = atan(2 * (a * a * b - x) / a / a / a) / M_PI * 180;

    if (ans > atan(b / a) / M_PI * 180) {
        ans = (M_PI / 2 - atan(2 * x / (a * b * b))) / M_PI * 180;
    }

    cout << setprecision(10) << ans;

    return 0;
}
