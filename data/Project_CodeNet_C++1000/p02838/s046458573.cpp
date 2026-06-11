#include <bits/stdc++.h>
using namespace std;

const long long MOD = (long long)1e9 + 7;

template <typename T>
T modPow(T base, T e, T mod) {
  if(e==0) return 1;
  if(e==1) return base%mod;
  if(e%(T)2==1) return (base * modPow(base, e-(T)1, mod)) %mod;
  
  T tmp = modPow(base, e/(T)2, mod);
  return (tmp * tmp) % mod;
}

int main(){
  long long N;
  cin >> N;
  
  long long A[N];
  
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  long long ans = 0;
  for (long long bit = 0; bit < 60; bit++) {
    long long bitCount = 0;
    for (int i = 0; i < (int)N; i++) {
      if((A[i]>>bit) & 1) bitCount++;
    }
    long long tmp = bitCount*(N-bitCount)%MOD;
    tmp *= modPow(2LL,bit,MOD);
    ans += tmp%MOD;
    ans %= MOD;
  }
  
  cout << ans % MOD << endl;

  return 0;
}