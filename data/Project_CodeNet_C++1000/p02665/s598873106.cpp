#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
void fail() {
    cout << -1;
    exit(0);
}
int main() {
    int n;
    cin >> n;
    ++n;
    vector<ll> a(n), b(n);
    for (ll& i : a) cin >> i;
    if (n == 1) return cout << (a[0] == 1 ? 1 : -1), 0;
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) b[i] = b[i + 1] + a[i];
    ++a[0];
    ll m = 1, r = 0;
    for (int i = 0; i < n; ++i) {
        r += m = min(m * 2ll, b[i]) - (i ? a[i] : b[0] <= 1 ? 0 : a[i]);
        if (m < 0) return cout << "-1\n", 0;
    }
    rep(i, n) r += a[i];
    cout << r - 1 << endl;
    return 0;
}