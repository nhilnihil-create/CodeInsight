// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

ll dp[3001][3001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    const ll MOD = 998244353;
    int n,s; cin >> n >> s;
    int a[n]; rep(i,n) cin >> a[i];
  	dp[0][0] = 1LL;
    rep(i,n){
        for(int j = 0; j <= s; ++j){
            dp[i+1][j] += 2*dp[i][j];
          	dp[i+1][j] %= MOD;
          	if(j - a[i] >= 0){
              dp[i+1][j] += dp[i][j-a[i]];
              dp[i+1][j] %= MOD;
            }
        }
    }
  
    cout << dp[n][s] << endl;
}