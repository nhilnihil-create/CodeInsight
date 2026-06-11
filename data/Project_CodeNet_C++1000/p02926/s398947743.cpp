#include <iostream>
#include <cfloat>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;
using llong = long long;

llong n;
tuple<double, llong, llong> p[128];

double f(tuple<double, llong, llong>a, tuple<double, llong, llong> b) {
    double arg1 = get<0>(a);
    double arg2 = get<0>(b);
    double ang = fabs(arg1 - arg2);
    return min(ang, fabs(2 * M_PI - ang));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        llong x, y;
        cin >> x >> y;
        p[i] = make_tuple(atan2(y, x), y, x);
    }
    sort(p, p + n);

    double ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            llong x = 0, y = 0;
            for (int j = 0; j < k; j++) {
                x += get<2>(p[(i + j) % n]);
                y += get<1>(p[(i + j) % n]);
            }
            ans = max(ans, sqrt(x * x + y * y));
        }
    }


    printf("%.*lf\n", 15, ans);
}