#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll MOD = 1000000007;
  int n, m;
  cin >> n >> m;
  vi broken(n+1);
  vi a(n);
  rep(i,m){
    cin >> a[i];
    broken[a[i]] = 1;
  }
  vector<ll> dp(n+1);
  dp[0] = 1; 
  if(a[0] == 1) dp[1] = 0;
  else dp[1] = 1;
  for(ll i=2; i<=n; i++){
    if(broken[i] == 1) {
      dp[i] = 0;
      continue;
    }
    dp[i] = (dp[i-1] + dp[i-2]) % MOD;
  }
  cout << dp[n] << endl;
}
