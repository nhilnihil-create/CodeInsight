#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, t;
  cin >> n >> t;
  vector < ll > a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

  ll dp1[n + 1][t + 1];
  memset(dp1, 0, sizeof(dp1));
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= t; j++){
      if(j - a[i] >= 0){
        dp1[i][j] = max(dp1[i - 1][j], b[i] + dp1[i - 1][j - a[i]]);
      }else dp1[i][j] = dp1[i - 1][j];
    }
  }

  ll dp2[n + 1][t + 1];
  memset(dp2, 0, sizeof(dp2));
  for(int j = 0; j <= t; j++){
    if(j >= a[n]) dp2[n][j] = b[n];
  }
  for(int i = n - 1; i > 0; i--){
    for(int j = 0; j <= t; j++){
      if(j - a[i] >= 0){
        dp2[i][j] = max(dp2[i + 1][j], b[i] + dp2[i + 1][j - a[i]]);
      }else dp2[i][j] = dp2[i + 1][j];
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < t; j++){
      if(i != n) ans = max(ans, dp1[i - 1][j] + dp2[i+ 1][t - 1 - j] + b[i]);
      else ans = max(ans, dp1[n - 1][j] + b[n]);
    }
  }

  cout << ans << '\n';
}
