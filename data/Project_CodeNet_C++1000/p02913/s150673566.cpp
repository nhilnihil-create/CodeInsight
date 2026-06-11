#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
   int n;
   cin >> n;
   string s;
   cin >> s;
    int dp[n][n];
    rep(i,n) rep(j,n) dp[i][j]=0;
   rep(i,n) {
       if(s[i]==s[0])dp[i][0]=1;
       if(s[0]==s[i])dp[0][i]=1;
   }
   FOR(i,1,n) {
       FOR(j,1,n) {
           if(s[i]==s[j])dp[i][j]=dp[i-1][j-1]+1;
            //cout << dp[i][j] << flush;
       }
   //    cout << "" << endl;
   }
    int ans = 0;
    int tmp = inf;
    rep(i,n) {
        rep(j,n) {
            if(j>=i) continue;
            tmp = min(dp[i][j],i-j);
           // cout << tmp << endl;
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;



  return 0;
}
