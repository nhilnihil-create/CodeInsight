#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  rep(i, m) cin >> v[i];

  vector<ll> dp(n+10, 0);
  rep(i, m) dp[v[i]] = -1; 
  dp[0] = 1;
  rep(i, n){
    if (dp[i] == -1) continue;
    if (dp[i+1] != -1) dp[i+1] = (dp[i+1] + dp[i]) % 1000000007;
    if (dp[i+2] != -1) dp[i+2] = (dp[i+2] + dp[i]) % 1000000007;
  }
  cout << dp[n] << endl;
  return 0;
}