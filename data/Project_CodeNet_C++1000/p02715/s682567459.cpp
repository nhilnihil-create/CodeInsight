#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll modpow(ll m, ll n){
  if(n == 0) return 1;
  else if(n % 2 == 0) return modpow(m * m % MOD, n/2);
  else{
    return modpow(m, n - 1) * m % MOD;
  }
}

int main(){
    int n, k; scanf("%d %d", &n, &k);
    ll ans = 0;
    vector<ll> data(k + 1, 0);

    for(int g = k; g >= 1; g--){
        ll cnt = modpow(k/g, n);
        for(int i = g; i <= k; i += g){
            (cnt += -data[i] + MOD) %= MOD;
        }
        data[g] = cnt;
        (ans += (cnt * g)%MOD) %= MOD;
    }

    printf("%lld\n", ans);
}