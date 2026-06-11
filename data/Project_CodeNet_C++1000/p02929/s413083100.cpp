#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s;
    ll ans = 1, mod = 1e9 + 7;
    rep(i, 0, n) t += "BW";
    vector<int> l(2 * n), r(2 * n), d(2 * n);
    rep(i, 0, 2 * n) {
        if (i) {
            l[i] = l[i - 1];
            r[i] = r[i - 1];
        }
        if (t[i] == s[i])
            l[i]++;
        else
            r[i]++;
        d[i] = (t[i] != s[i]);
        if (l[i] < r[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    if (l[2 * n - 1] != r[2 * n - 1]) {
        cout << 0 << endl;
        return 0;
    }
    ll c = 0;
    rep(i, 0, 2 * n) if (d[i]) {
        ans = ans * (l[i] - c) % mod;
        c++;
    }
    for (ll i = 1; i <= n; i++) {
        ans = ans * i % mod;
    }
    cout << ans << endl;
    return 0;
}
