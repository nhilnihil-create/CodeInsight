#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;

int main(){
  ll p = pow(10, 9) + 7;
  vector<ll> fac(2020);
  vector<ll> inv(2020);
  vector<ll> fac_inv(2020);
  fac[0] = 1; fac[1] = 1;
  inv[0] = 1; inv[1] = 1;
  fac_inv[0] = 1;  fac_inv[1] = 1;
  for(ll i = 2; i <= 2010; i++){
    fac[i] = fac[i-1] * i % p;

    inv[i] = p - inv[p % i] * (p / i) % p;
    
    fac_inv[i] = fac_inv[i-1] * inv[i] % p;
  }

  ll n, k;
  cin >> n >> k;

  ll res;
  for(ll i = 1; i <= k; i++){
    ll a, b;
    if(n-k+1>=i){
    a = ((fac[n-k+1] * (fac_inv[i] * fac_inv[n-k+1-i] % p) % p)%p);
    }
    else{a = 0;}
    if(k-1>=i-1){
    b = ((fac[k-1] * (fac_inv[i-1] * fac_inv[k-1-i+1] % p) % p)%p);
    }
    else{b = 0;}
    res = a*b;
    res %= p;
    cout << res << endl;
  }

}    