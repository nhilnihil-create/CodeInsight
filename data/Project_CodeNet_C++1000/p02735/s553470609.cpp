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
char a[110][110];
int dp[110][110];
signed main() {
    int h, w;
    cin >> h>>w;

    rep(i,h+2) rep(j, w+2) a[i][j]='.';
    FOR(i,1,h+1) {
        string s;
        cin>>s;
        FOR(j,1,w+1) {
            a[i][j]= s[j-1];
        }
    }

    FOR(j,1,w+2) {
        dp[1][j]=dp[1][j-1]+((a[1][j]!=a[1][j-1])?1:0);        
        dp[j][1]=dp[j-1][1]+((a[j][1]!=a[j-1][1])?1:0);   
        // cout <<(a[1][j]!=a[1][j-1])<<" "<<j<<" "<<a[1][j]<<" "<<a[1][j-1]<<" "<<" "<<dp[1][j-1]<< dp[1][j] << endl;    
    }
    FOR(i,2,h+1) {
        FOR(j,2,w+1) {
            int ii = ((a[i-1][j]!=a[i][j])?1:0);
            int jj = ((a[i][j-1]!=a[i][j])?1:0);
            dp[i][j]=min(dp[i-1][j]+ii,dp[i][j-1]+jj);
        }
    }
    // rep(i,h+2) {
    //     rep(j,w+2) {
    //         cout << dp[i][j]<<flush;
    //     }
    //     cout << "" << endl;
    // }
    int ans = dp[h][w] + ((a[h][w+1]!=a[h][w])?1:0);
    cout << ans/2 << endl;

  return 0;
}

