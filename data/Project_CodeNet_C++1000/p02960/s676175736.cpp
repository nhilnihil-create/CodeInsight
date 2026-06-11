#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

const ll mod = 1000000007;
ll modPow(ll a, ll n, ll md){
  if (n == 0) return 1;
  if (n == 1) return a % md;
  if (n % 2 == 1) return (a * modPow(a, n-1, md)) % md;
  ll t = modPow(a, n/2, md);
  return (t * t) % md;
}

int main(){
  string s;
  cin >> s;
  ll n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(13, 0));
  dp[0][0] = 1;
  rep(i, n){
    ll x = modPow(10, i, 13);
    if (s[n-i-1] == '?'){
      rep(j, 13)rep(k, 10){
        dp[i+1][(j+k*x)%13] += dp[i][j];
        dp[i+1][(j+k*x)%13] %= mod;
      }
    }
    else{
      ll k = s[n-i-1] - '0';
      rep(j, 13){
        dp[i+1][(j+k*x)%13] += dp[i][j];
        dp[i+1][(j+k*x)%13] %= mod;
      }
    }
  }
  cout << dp[n][5] << endl;
  
  return 0;
}