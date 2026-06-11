#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define erep(i, n) for(ll i = 1; i <= (n); i++)
#define trep(i, a, n) for(ll i = a; i <= (n); i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(void) {
  int n, m, a;
  cin >> n >> m;
  vector<bool> steps(n+10, true);
  rep(i, m){
    cin >> a;
    steps[a] = false;
  }
  vector<ll> dp(n+10,0);
  dp[0]=1;
  if(steps[1])dp[1]=1;
  trep(i, 2, n){
    if(steps[i-1]) dp[i] += dp[i - 1]; 
    if(steps[i-2]) dp[i] += dp[i - 2];
    dp[i] %= MOD;
  }
  cout << dp[n] << '\n';
  return 0;
}