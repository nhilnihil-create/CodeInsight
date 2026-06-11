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
  if(ex == 0){
    return 1;
  } else{
    if(ex % 2 == 0){
      return power_mod((bs % MOD) * (bs % MOD), ex / 2) % MOD;
    } else{
      return (bs % MOD) * power_mod((bs % MOD), ex - 1) % MOD;
    }
  }
}

int main(){
  ll N, K;
  cin >> N >> K;

  vl fact(N + 1, 0);
  vl fact_inv(N + 1, 0);

  fact[0] = 1;
  rep2(i, 1, N + 1) fact[i] = fact[i - 1] * i % MOD;

  fact_inv[N] = power_mod(fact[N], (ll)pow(10, 9) + 5);
  rep_inv(i, N - 1, -1) fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;

  ll comb1, comb2, ans;

  rep2(i, 1, K + 1){
    if(N - K + 1 < i){
      cout << 0 << "\n";
    } else{
      comb1 = fact[K - 1] * fact_inv[i - 1] % MOD * fact_inv[K - i] % MOD;
      comb2 = fact[N - K + 1] * fact_inv[i] % MOD * fact_inv[N - K + 1 - i] % MOD;
      
      ans = comb1 * comb2 % MOD;
      
      cout << ans << "\n";
    }    
  }
  
  return 0;
}
