#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll mod=1e9+7;

int main() {
  string l;
  cin >> l;
  vector<vector<ll>> dp(l.size(),vector<ll>(2));
  dp[0][0]=1;
  dp[0][1]=2;
  for(ll i=1;i<l.size();i++) {
    if(l[i]=='1') {
      dp[i][1]=dp[i-1][1]*2%mod;
      dp[i][0]=dp[i-1][1];
    }
    else {
      dp[i][1]=dp[i-1][1];
    }
    dp[i][0]=(dp[i][0]+dp[i-1][0]*3)%mod;
  }
  ll ans=(dp[l.size()-1][0]+dp[l.size()-1][1])%mod;
  cout << ans << endl;
}