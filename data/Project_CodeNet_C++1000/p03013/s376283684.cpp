#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7;

int main() {
  int n,m; cin>>n>>m;
  vector<bool> isStairBroken(n+10,false);
  for(int i=0;i<m;i++) {
    int t; cin>>t;
    isStairBroken[t] = true;
  }
  vector<ll> dp(n+10,0);
  dp[0]=1;
  // 1つ前が壊れてない + 2つ前が壊れてない  dp[i] = dp[i-1]+dp[i-2]
  // 1つ前が壊れてない + 2つ前が壊れてる    dp[i] = dp[i-1]
  // 1つ前が壊れてる + 2つ前が壊れてない dp[i] = dp[i-2]
  for(int i=0;i<=n-1;i++) {
    // チェックする階段が壊れていない
    if(!isStairBroken[i]) {
      // 1段目ok 2段目ok
      if(!isStairBroken[i+1]) (dp[i+1]+=dp[i])%=MOD;
      if(!isStairBroken[i+2]) (dp[i+2]+=dp[i])%=MOD;
    }
  }
  cout << dp[n] << endl;
}
