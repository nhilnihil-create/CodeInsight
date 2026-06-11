#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
vector<ll> fact_inv, inv, Com;

ll POW(ll a, ll n){ return n ? POW(a*a%MOD, n/2) * (n%2?a:1)%MOD : 1;} 
 
void init_nCk(ll n, ll SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
    Com.resize(SIZE + 5);
    Com[0] = 1;
    for (ll i = 1; i < SIZE + 5; i++) {
        Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
    }
}

ll nCk(ll k) {
    return Com[k];
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  init_nCk(n, 2e5);
  
  ll ca, cb;
  ca = nCk(a);
  cb = nCk(b);
  
  ll ret = POW(2,n);
  ret = (ret - ca - cb - 1) % MOD;
  if(ret < 0) ret += MOD;
  
  cout << ret << endl;
  return 0;
}