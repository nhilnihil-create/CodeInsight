#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

const int N = 3030;
const int MOD = 998244353;

int n,s;
int a[N];
int dp[N][N];

signed main(){
   IOS;
   cin >> n >> s;
   for(int i = 0; i < n; ++i){
      cin >> a[i+1];
   }
   dp[0][0] = 1;
   for(int i = 1; i <= n; ++i) { 
      for(int j = 0; j < N; ++j) {
         if(dp[i-1][j]) {
            if(j + a[i] < N) {
               dp[i][j+a[i]] = (dp[i][j+a[i]] + dp[i-1][j]) % MOD;
            }
            dp[i][j] = (2*dp[i-1][j] + dp[i][j])%MOD;
         }
      }
   }
   cout << dp[n][s] << '\n';
}