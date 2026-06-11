#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vt<int> a(n), f(n);
    for (int &i : a) cin >> i;
    for (int &i : f) cin >> i;

    sort(all(a));
    sort(rall(f));

    ll l = 0, r = 1ll << 60;
    while (l < r) {
        ll mi = (l + r) / 2;

        ll train = 0;
        for (int i = 0; i < n; i++) {
            if ((ll)a[i] * f[i] <= mi) continue;
            train += a[i] - mi / f[i];
        }

        if (train > k) l = mi + 1;
        else r = mi;
    }

    cout << l;
}
