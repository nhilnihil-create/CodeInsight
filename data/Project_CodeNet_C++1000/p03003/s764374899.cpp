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

  ll dp[n + 2][m + 2];
  for(int j = 0; j < m + 2; j++) dp[n + 1][j] = 0;
  for(int i = 0; i < n + 2; i++) dp[i][m + 1] = 0;

  for(int i = n; i > 0; i--){
    for(int j = m; j > 0; j--){
      if(a[i] == b[j]){
        dp[i][j] = 1 + dp[i + 1][j] + dp[i][j + 1];
      }
      else{
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
      }
      dp[i][j] = (dp[i][j] + mod) % mod;
      //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }
  }

  cout << (dp[1][1] + 1) % mod << endl;
}
