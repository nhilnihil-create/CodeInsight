#include <bits/stdc++.h>
#define PI 3.14159265
using namespace std;
using ld = long double;
const ld EPS = 0.0000000001;
ld a, b, x;

ld f(ld a, ld b, ld theta) {
    if (theta > PI / 2.0 - EPS) {
        return 0.0;
    }
    ld ret;
    if (a * tan(theta) <= b) {
        ret = a * a * b - a * a * a * tan(theta) / 2.0;
    } else {
        return b * b / tan(theta) * a / 2.0;
    }
    return ret;
}

void solve() {
    cin >> a >> b >> x;
    ld r = PI / 2.0;
    ld l = 0.0;
    for (int i = 0; i < 100000; ++i) {
        ld mid = (l + r) / 2.0;
        if (f(a, b, mid) < x) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(10) << r / PI * 180 << endl;
}

int main() {
    solve();
    return 0;
}
