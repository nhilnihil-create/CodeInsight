#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const double pi = acos(-1);
const double eps = 0.000000001;

double a, b, x;

double func(double theta) {
    if (theta >= pi / 2.0) {
        return 0.0;
    }
    double r;
    if (b / tan(theta) > a) {
        r = a * a * b - a * a * a * tan(theta) / 2.0;
    } else {
        r = a * b * b / tan(theta) / 2.0;
    }
    return r;
}

int main() {
    cout << fixed << setprecision(10);
    cin >> a >> b >> x;
    double ok =  0.0;
    double ng = pi / 2.0;
    rep(i, (int)1e6) {
        double mid = (ok + ng) / 2.0;
        if (func(mid) >= x) ok = mid;
        else ng = mid;
    }
    cout << ok / pi * 180 << endl;
}