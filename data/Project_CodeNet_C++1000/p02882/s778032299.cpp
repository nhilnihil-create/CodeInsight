#include <bits/stdc++.h>

using namespace std;

void solve() {
    double a, b, x;
    cin >> a >> b >> x;
    double l;
    l = 2 * x / a / b;
    double t, ans;
    if (l <= a)
    {
        t = b / l;
    }
    else
    {
        t = (2 * a * a * b - 2 * x) / a / a / a;
    }
    ans = atan(t) * 180 / M_PI;
    cout << fixed << setprecision(15)<< ans << endl;
}

int main() {
    solve();
    return 0;
}