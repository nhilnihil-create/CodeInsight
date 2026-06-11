#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll MOD = (ll)pow(10, 9) + 7;

ll power_mod(ll bs, ll ex){
  if(ex == 0)
    return 1;
  else if(ex % 2 == 0)
    return power_mod(bs * bs % MOD, ex / 2) % MOD;
  else
    return bs * power_mod(bs, ex - 1) % MOD;
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;

  if(n == 2){
    cout << 0 << "\n";
    return 0;
  }

  vl fact(b + 1), fact_inv(b + 1);

  fact[0] = 1;
  rep2(i, 1, b + 1) fact[i] = fact[i - 1] * i % MOD;

  fact_inv[b] = power_mod(fact[b], MOD - 2);
  rep_inv(i, b - 1, -1){
    fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;
    // cout << i << ' ' << fact[i] << ' ' << fact_inv[i] << ' ' << fact[i] * fact_inv[i] % MOD << "\n";
  }

  ll whole = power_mod(2, n) - 1;
  ll comb_a = fact_inv[a];
  ll comb_b = fact_inv[b];

  rep(i, a) comb_a = comb_a * (n - i) % MOD;
  rep(i, b) comb_b = comb_b * (n - i) % MOD;

  // cout << whole << ' ' << comb_a << ' ' << comb_b << "\n";
  
  ll ans = 0;

  if(whole >= comb_a)
    ans = whole - comb_a;
  else
    ans = whole - comb_a + MOD;

  if(ans >= comb_b)
    ans = ans - comb_b;
  else
    ans = ans - comb_b + MOD;

  cout << ans << "\n";
    
  return 0;
}
