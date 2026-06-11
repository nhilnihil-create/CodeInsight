#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
int main(){
  ll s;
  cin >> s;
  if(s < 3){ cout << 0 << endl; return 0; }
  ll dp[2000];
  dp[0] = dp[1] = dp[2] = 1;
  for(int i=3; i<=s-3; ++i){
    dp[i] = (dp[i-1]+dp[i-3])%mod;
  }
  cout << dp[s-3] << endl;
}