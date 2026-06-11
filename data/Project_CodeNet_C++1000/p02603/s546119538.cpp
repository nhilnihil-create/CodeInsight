#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[85][2][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    dp[0][0][0] = 1000;
    dp[0][0][1] = 0;
    dp[0][1][0] = 1000;
    dp[0][1][1] = 0;
    rep(i,n){
        dp[i+1][0][0] = dp[i][0][0] + a[i] * dp[i][0][1];
        dp[i+1][0][1] = 0;
        ll mon = dp[i][1][0] + a[i] * dp[i][1][1];
        if(dp[i+1][0][0] < mon){
            dp[i+1][0][0] = mon;
            dp[i+1][0][1] = 0;
        }
        ll stk = dp[i][0][0] / a[i];
        dp[i+1][1][1] = dp[i][0][1] + stk;
        dp[i+1][1][0] = dp[i][0][0] - stk * a[i];
        stk = dp[i][1][0] / a[i];
        if(dp[i+1][1][1] < stk + dp[i][1][1]){
            dp[i+1][1][1] = stk + dp[i][1][1];
            dp[i+1][1][0] = dp[i][1][0] - stk * a[i];
        }
        else if(dp[i+1][1][1] == stk + dp[i][1][1]){
            chmax(dp[i+1][1][0], dp[i][1][0] - stk * a[i]);
        }
    }
    ll ans = max(dp[n][0][0], dp[n][1][0]);
    cout << ans << endl;
    return 0;
}
