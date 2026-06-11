#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll mod = 1e9 + 7;
 
int main(){
  int n; cin >> n;
  vector<pair<ll, int>> p(n);
  vector<int> y(n);
  rep(i, n){
    cin >> p[i].first;
    p[i].second = i + 1;
    y[i] = i + 1;
  }

   sort(p.begin(), p.end(), greater<pair<ll, int>>());
  
  vector<vector<ll>> dp(n+1,vector<ll>(n+1));
  dp[0][0] = 0;
  for(int i=1; i<n+1; i++){
  dp[i][0] = dp[i-1][0] + p[i-1].first*abs(p[i-1].second - i);
  dp[0][i] = dp[0][i-1] + p[i-1].first*abs(n-(i-1)-p[i-1].second);
  }
  
  ll ans = max(dp[n][0], dp[0][n]);
  for(int i=1; i<n+1; i++){
  	for(int j=1; j<n+1-i; j++){
  ll x_p1 = dp[i-1][j] +  p[i+j-1].first*abs(p[i+j-1].second- i);    
  ll y_p1 = dp[i][j-1] +  p[i+j-1].first*(n-(j-1)-p[i+j-1].second);   
      dp[i][j] = max(x_p1, y_p1);
      if( i + j == n ) ans = max(ans, dp[i][j]);
    }
  }
   cout << ans <<endl;
  
  
  return 0;
}
