//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    vvi c(m, vi(n));
    rep(i, m) {
        cin >> a[i] >> b[i];
        rep(j, b[i]) {
            cin >> c[i][j];
            --c[i][j];
        }
    }

    vvi dp(m+1, vi(1 << n, INF));
    dp[0][0] = 0;
    rep(i, m) {
        rep(j, 1 << n) {
            dp[i+1][j] = dp[i][j];
            int x = 0;
            rep(k, b[i]) {
                x |= 1<<c[i][k];
            }
            dp[i+1][j] = min(dp[i+1][j], dp[i][j & ~x] + a[i]);
        }
    }


    if(dp[m][(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[m][(1<<n)-1] << endl;
}
