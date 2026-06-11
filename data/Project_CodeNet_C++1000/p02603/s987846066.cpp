#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[85][2][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    dp[0][0][0] = 1000;
    dp[0][0][1] = 0;
    dp[0][1][0] = 1000;
    dp[0][1][1] = 0;
    rep(i,n){
        ll a;
        cin >> a;
        ll mon1 = dp[i][0][0] + dp[i][0][1] * a;
        ll stk1 = 0;
        dp[i+1][0][0] = mon1;
        dp[i+1][0][1] = 0;
        ll mon2 = dp[i][1][0] + dp[i][1][1] * a;
        ll stk2 = 0;
        chmax(dp[i+1][0][0], mon2);
        mon1 = dp[i][0][0] - (dp[i][0][0] / a) * a;
        stk1 = dp[i][0][1] + dp[i][0][0] / a;
        dp[i+1][1][0] = mon1;
        dp[i+1][1][1] = stk1;
        mon2 = dp[i][1][0] - (dp[i][1][0] / a) * a;
        stk2 = dp[i][1][1] + dp[i][1][0] / a;
        if(stk1 < stk2){
            dp[i+1][1][0] = mon2;
            dp[i+1][1][1] = stk2;
        }
        if(stk1 == stk2) chmax(dp[i+1][1][0], mon2);
    }
    ll ans = max(dp[n][0][0], dp[n][1][0]);
    cout << ans << endl;
    return 0;
}
