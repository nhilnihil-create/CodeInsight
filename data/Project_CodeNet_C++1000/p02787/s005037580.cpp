#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli h, n;

int main(void){
    cin >> h >> n;
    vector<lli> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    lli ma = *max_element(a.begin(), a.end());
    vector<lli> dp(h+ma+5, 1e9);
    dp[0] = 0;
    rep(i, h){
        rep(j, n){
            chmin(dp[i+a[j]], dp[i]+b[j]);
        }
    }
    lli ans = 1e18;
    for(int i = h; i <= h+ma; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
