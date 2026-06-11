#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

const ll mod = 1000000007;
int main(){
  ll n, m;
  cin >> n >> m;
  vector<bool> a(n+1, true);
  rep(i, m){
    ll x;
    cin >> x;
    a[x] = false;
  }
  vector<ll> dp(n+1, 0);
  dp[0] = 1;
  rep(i, n){
    if (a[i+1]) dp[i+1] = (dp[i] + dp[i+1]) % mod;
    if (i == n-1) break;
    if (a[i+2]) dp[i+2] = (dp[i] + dp[i+2]) % mod;
  }
  cout << dp[n] << endl;
  
  return 0;
}