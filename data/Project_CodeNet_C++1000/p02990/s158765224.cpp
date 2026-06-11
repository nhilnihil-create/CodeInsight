#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 2e3 + 5;

vector < ll > fact(MAXN);

ll pwr(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

ll inv(ll a){
  return pwr(a, mod - 2);
}

ll comb(ll n, ll r){
  if(r > n) return 0;
  return ((((fact[n] * inv(fact[r])) % mod) * inv(fact[n - r])) % mod);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++) fact[i] = (i * fact[i - 1]) % mod;

  ll n, k;
  cin >> n >> k;

  vector < ll > ans(k + 1);
  for(int i = 1; i <= k; i++){
    ans[i] = (comb(n - k + 1, i) * comb(k - 1, i - 1)) % mod;
  }

  for(int i = 1; i <= k; i++) cout << ans[i] << endl;
}
