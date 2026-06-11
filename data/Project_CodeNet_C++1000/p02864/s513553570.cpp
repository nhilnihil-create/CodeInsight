#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




ll dp[303][303][303];
// 番号, 左隣のありうる高さ, 減らせる回数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    
    const ll INF = 1e18;
    rep(i, 303) rep(j, 303) rep(l, 303) dp[i][j][l] = INF;
    dp[0][0][0] = h[0];
    dp[0][n][1] = 0;
    
    rep3(i, 1, n) {
        rep(l, k + 1) {
            rep(j, n) {
                if (dp[i - 1][j][l] == INF) continue;
                if (h[j] >= h[i]) {
                    // cout << i << " " << j << " " << l << endl;
                    chmin(dp[i][i][l], dp[i - 1][j][l]);
                } else {
                    chmin(dp[i][i][l], dp[i - 1][j][l] + h[i] - h[j]);
                }
                chmin(dp[i][j][l + 1], dp[i - 1][j][l]);
            }
            // 高さ0
            if (dp[i - 1][n][l] == INF) continue;
            // 加算
            chmin(dp[i][i][l], dp[i - 1][n][l] + h[i]);
            // 下げる
            chmin(dp[i][n][l + 1], dp[i - 1][n][l]);
        }
    }
    
    ll ans = 1e18;
    rep(j, n + 1) rep(l, k + 1) {
        if (dp[n - 1][j][l] == -1) continue;
        chmin(ans, dp[n - 1][j][l]);
    }
    cout << ans << endl;
    
    /*
    rep(i, n) {
        cout << endl;
        rep(j, n + 1) { rep(l, k + 1) cout << dp[i][j][l] << " "; cout << endl; }
    }
     */
}


