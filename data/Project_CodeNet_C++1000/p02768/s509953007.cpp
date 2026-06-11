#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;

template <typename T>
T modMinus(T a, T b, T mod) {
  return (a>b)? (a-b)%mod: modMinus(mod+a, b, mod);
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
  return (num*modPow(den, primeMod-(T)2, primeMod)) % primeMod;
}

template <typename T>
T modComb(T n, T k, T mod) {
  T num = (T)1; //numerator
  T den = (T)1; //denominator
  for (T i = (T)1; i <= k; i++) {
    num *= (n-i+1);
    num %= mod;
    den *= i;
    den %= mod;
  }
  return primeModDiv(num, den, mod);
}

int main(){
  long long n, a, b;
  cin >> n >> a >> b;

  long long ans = modPow(2LL, n, MOD)-1LL;
  ans = modMinus(ans,modComb(n,a,MOD),MOD);
  ans = modMinus(ans,modComb(n,b,MOD),MOD);
  
  cout << ans << endl;
  
}
