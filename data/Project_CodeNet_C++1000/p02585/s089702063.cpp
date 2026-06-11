#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;

const int N = 5000;

ll n, k;
ll p[N], c[N];
ll g[N], gs[N], tot[N];

int counter = -1;
bitset<N> vis;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vis.reset();
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++counter;
            for (int j = i; !vis[j]; j = p[j]) {
                // cout << j << ' ';
                vis[j] = true;
                g[j] = counter;
                tot[counter] += c[j];
                gs[counter]++;
            }
            // cout << '\n';
        }
    }

    ll ans = -1e18;
    for (int i = 0; i < n; ++i) {
        ll tmp = 0, mx = -1e18;
        int cur = i;
        for (int j = 0; j < min(k, gs[g[i]]); ++j) {
            tmp += c[cur];
            ll cycles = (k - j - 1) / gs[g[i]];
            mx = max(mx, tmp + max(0ll, cycles * tot[g[i]]));
            cur = p[cur];
        }
        ans = max(mx, ans);
    }
    cout << ans;
}
