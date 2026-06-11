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

    int n, m;
    cin >> n >> m;
    vt<bool> vis(n);
    int oddSize = (m + 1) / 2 * 2,
        evenSize = m / 2 * 2 + 1;
    for (int i = 0; i < m; i++) {
        int x = i / 2;
        if (~i & 1) cout << x + 1 << ' ' << oddSize - x << '\n';
        else cout << n - evenSize + x + 1 << ' ' << n - x << '\n';
    }
}
