#include <bits/stdc++.h>
using namespace std;

const long MOD = 1e9+7;

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
  if (k > n-k) k = n-k;
  for (T i = 1; i <= k; i++) {
    num *= (n-i+(T)1);
    num %= mod;
    den *= i;
    den %= mod;
  }
  return primeModDiv(num, den, mod);
}

int main(){
  long X, Y;
  cin >> X >> Y;
  
  long xMove1 = -1;
  long xMove2 = -1;
  for (int move2 = 0; move2 <= X/2; move2++) {
    int move1 = X - 2*move2;
    if (Y==2*move1+move2) {
      xMove1 = move1;
      xMove2 = move2;
      break;
    }
  }
    
  if (xMove1==-1) {
    cout << 0 << endl;
    return 0;
  }
  cout << modComb(xMove1+xMove2, xMove1, MOD) << endl;
  
}