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

const int inf = 1 << 30;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vt<int> dp(1 << n, inf);
    dp[0] = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int mask = 0;
        while (b--) {
            int x;
            cin >> x;
            mask |= 1 << x - 1;
        }

        for (int i = sz(dp) - 1; i >= 0; i--) {
            int &x = dp[i | mask];
            x = min(x, dp[i] + a);
        }
    }

    cout << (dp.back() == inf ? -1 : dp.back());
}
