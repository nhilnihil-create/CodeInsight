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
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




// けんちょんさんの記事

ll dp[2004][2004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    int n, m;
    cin >> n >> m;
    
    vector<int> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];
    
    
    rep(i, n + 1) dp[i][0] = 1;
    rep(j, m + 1) dp[0][j] = 1;
    
    rep(i, n + 1) rep(j, m + 1) {
        (dp[i + 1][j + 1] += dp[i + 1][j]) %= inf;
        (dp[i + 1][j + 1] += dp[i][j + 1]) %= inf;
        if (s[i] == t[j]) {
            (dp[i + 1][j + 1] += dp[i][j]) %= inf;
        }
        (dp[i + 1][j + 1] += -dp[i][j] + inf) %= inf;
    }
    // rep(i, n + 1) { rep(j, m + 1) cout << dp[i][j] << " "; cout << endl; }
    cout << dp[n][m] << endl;
}


