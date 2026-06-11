#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

constexpr int N = 26;
constexpr int D = 365;

signed main() {
    int tt;
    cin >> tt;
    int c[N];
    rep(i, N) {
        cin >> c[i];
    }
    int s[D][N];
    rep(i, D) {
        rep(j, N) {
            cin >> s[i][j];
        }
    }
    int t[D];
    rep(i, D) {
        cin >> t[i];
        t[i]--;
    }
    int last[N];
    fill(last, last + N, -1);
    int ans = 0;
    rep(i, D) {
        last[t[i]] = i;
        ans += s[i][t[i]];
        rep(j, N) {
            ans -= c[j] * (i - last[j]);
        }
        cout << ans << endl;
    }
    return 0;
}