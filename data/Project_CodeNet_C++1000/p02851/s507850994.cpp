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

    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    ll ans = 0;
    vt<int> b(n + 1);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[b[i]]++;
        if (i >= k - 1) m[b[i - k + 1]]--;
        b[i + 1] = ((b[i] - a[i] + 1) % k + k) % k;
        if (m.count(b[i + 1])) ans += m[b[i + 1]];
    }

    cout << ans;
}
