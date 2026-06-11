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
  dp[0] = 1;
  dp[1] = 1;
  rep(i, m) dp[v[i]] = -1;
  int mo = 1e9 + 7;
  for(int i = 2; i <= n; ++i){
    if (dp[i] == -1) continue;
    ll s1 = dp[i-1];
    ll s2 = dp[i-2];
    if (s1 == -1) s1 = 0;
    if (s2 == -1) s2 = 0;

    dp[i] = (s1 + s2) % 1000000007;
  }
  cout << dp[n] << endl;
  return 0;
}