// 6/26 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    double ans;

    if (x >= a * a * b / 2.0) {
        // 台形の形からこぼれ始める。
        ans = atan(2.0*(a*a*b-x)/(a*a*a));
    } else {
        ans = (M_PI/2.0) - atan(2.0*x/(a*b*b));
    }

    cout << fixed << setprecision(15);
    cout << ans * 180.0 / M_PI << endl;
}