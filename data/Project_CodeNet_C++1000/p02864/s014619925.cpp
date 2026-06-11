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




ll dp[303][303];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n, k;
    cin >> n >> k;
    if (n == k) { cout << 0 << endl; return 0; }
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    
    const ll INF = 1e18;
    rep(i, 303) rep(j, 303) dp[i][j] = INF;
    // x番目は削除しない
    // 初期値は項数1以上
    rep(x, n) {
        dp[x][1] = h[x];
    }
    
    rep3(y, 2, n + 1) rep(x, n) {
        rep(i, x) {
            if (dp[i][y - 1] == INF) continue;
            chmin(dp[x][y], dp[i][y - 1] + max(0, h[x] - h[i]));
        }
    }
    ll ans = INF;
    rep(i, n) chmin(ans, dp[i][n - k]);
    cout << ans << endl;
}


