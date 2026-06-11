#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
  string s; cin >> s;
  int n = s.size();
  vector<ll> dp1(n + 1, 0), dp2(n + 1, 0);
  dp2[0] = 1;
  for(int i = 0; i < n; i++){
    (dp1[i + 1] += 3 * dp1[i]) %= MOD;
    if(s[i] == '1'){
      (dp1[i + 1] += dp2[i]) %= MOD;
      (dp2[i + 1] += 2 * dp2[i]) %= MOD;
    }
    else{
      (dp2[i + 1] += dp2[i]) %= MOD;
    }
  }
  ll ans = (dp1[n] + dp2[n]) % MOD;
  printf("%lld\n", ans);
}