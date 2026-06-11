#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
inline i64 Calc(i64 x, i64 p) {
    return x / p;
}
int n;
i64 a, b, c, d, res, p;
int main() {
    cin >> a >> b;
    n = 2;
    vector<i64> v(n);
    for (i64& x : v) {
        cin >> x;
        res += (Calc(b, x) - Calc(a - 1, x));
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            p = v[i] * v[j] / __gcd(v[i], v[j]);
            res -= (Calc(b, p) - Calc(a - 1, p));
        }
    res = (b - a + 1) - res;
    cout << res;
    return 0;
}
