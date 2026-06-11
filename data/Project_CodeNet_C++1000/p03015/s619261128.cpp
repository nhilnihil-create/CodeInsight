#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

ll mod = (ll)(1e9+7);

int main(){
  string L;
  cin >> L;

  vector<vector<ll>> dp(100005,vector<ll>(2));
  dp[0][0] = 1;
  
  rep(i,L.size()){
    // i桁目が0になるような遷移
    if(L[i]=='0'){
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][1];
    }else{
      dp[i+1][1] +=  (dp[i][0]+dp[i][1]);
      dp[i+1][1] %= mod;
    }

    // i桁目が1になるような遷移
    if(L[i]=='0'){
      dp[i+1][1] += dp[i][1]*2;
      dp[i+1][1] %= mod;
    }else{
      dp[i+1][0] += dp[i][0]*2;
      dp[i+1][0] %= mod;
      dp[i+1][1] += dp[i][1]*2;
      dp[i+1][1] %= mod;
    }
  }

  ll ans = dp[L.size()][0]+dp[L.size()][1];
  ans %= mod;
  cout << ans << endl;

  return 0;
} 

