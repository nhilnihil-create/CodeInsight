#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 1e5 + 5;
const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  vector < ll > a(n + 1), b(m + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) cin >> b[i];

  ll dp[n + 1][m + 1], sum[n + 1][m + 1];
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      sum[i][j] = 0;
      dp[i][j] = 0;
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i] == b[j]){
        dp[i][j] = sum[i - 1][j - 1] + 1;
        dp[i][j] %= mod;
      }
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + dp[i][j];
      sum[i][j] = (sum[i][j] + mod) % mod;
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      ans += dp[i][j];
      ans %= mod;
    }
  }
  ans = (ans + 1) % mod;

  cout << ans << endl;
}
