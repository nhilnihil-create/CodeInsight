#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vt<pii> pos(n);
    for (pii &i : pos) cin >> i.fi >> i.se;

    vt<int> per(n);
    iota(all(per), 0);
    double ans = 0;
    int cnt = 0;
    do {
        for (int i = 1; i < n; i++) {
            ans += hypot(pos[per[i]].fi - pos[per[i - 1]].fi,
                    pos[per[i]].se - pos[per[i - 1]].se);
        }
        cnt++;
    } while (next_permutation(all(per)));

    cout << setprecision(7) << fixed << ans / cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
