#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9+7;

template <typename T>
T modMinus(T a, T b, T mod) {
  a %= mod;
  b %= mod;
  return (a>b)? (a-b)%mod: (mod+a-b)%mod;
}

template <typename T>
T modPow(T base, T e, T mod) {
  if(e==0) return 1;
  if(e==1) return base%mod;
  if(e%(T)2==1) return (base * modPow(base, e-(T)1, mod)) %mod;
  
  T tmp = modPow(base, e/(T)2, mod);
  return (tmp * tmp) % mod;
}

template <typename T>
T primeModDiv(T num, T den, T primeMod){
  return ( num*modPow(den, primeMod-(T)2, primeMod) )%primeMod;
}

template <typename T>
T modComb(T n, T k, T mod) {
  T num = (T)1; //numerator
  T den = (T)1; //denominator
  for (T i = 1; i <= k; i++) {
    num *= (n-i+(T)1);
    num %= mod;
    den *= i;
    den %= mod;
  }
  return primeModDiv(num, den, mod);
}


int main() {
  ll N, K;
  cin >> N >> K;

  for (ll i = 1; i <= K; i++) {
    ll cmb = modComb((N-K)+1, i, MOD);
    cout << cmb*modComb(K-1, i-1, MOD)%MOD << endl;
  }

  return 0;
}