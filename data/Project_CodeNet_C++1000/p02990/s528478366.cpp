#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LIMIT 1000000007 //10^9+7

namespace /* combination.cpp */{
  namespace /* modinv.cpp */{
    namespace /* extGCD.cpp */{
      long long extGCD(long long a, long long b, long long &x, long long &y) {
          if (b == 0) {
              x = 1;
              y = 0;
              return a;
          }
          long long d = extGCD(b, a%b, y, x);
          y -= a/b * x;
          return d;
      }
    }
    long long modinv(long long a, long long p){
      long long x, y;
      extGCD(a, p, x, y);
      return (x>0? x: x+p);
    }
  }
  long long l_fac(long long n){
    if(n<0) return -1;
    long long ans = 1;
    for(long long i=1; i<=n; i++){
      ans *= i;
      ans %= LIMIT;
    }
    return ans;
  }
  long long l_nPr(long long n, long long r){
    long long ans = 1;
    for(long long i=0; i<r; i++){
      ans *= (n-i);
      ans %= LIMIT;
    }
    return ans;
  }
  long long l_nCr(long long n, long long r){
    return l_nPr(n, r) * modinv(l_fac(r), LIMIT) % LIMIT;
  }
}


namespace /* COMfast.cpp */{
  #define COMMAX 1000000 //0.15sで構築可能
  long long fac[COMMAX], finv[COMMAX], inv[COMMAX];
  // テーブルを作る前処理
  void COMinit() {
      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1] = 1;
      for (int i = 2; i < COMMAX; i++){
          fac[i] = fac[i - 1] * i % LIMIT;
          inv[i] = LIMIT - inv[LIMIT%i] * (LIMIT / i) % LIMIT;
          finv[i] = finv[i - 1] * inv[i] % LIMIT;
      }
  }

  // 二項係数計算
  long long COM(int n, int k){
      if (n < k) return 0;
      if (n < 0 || k < 0) return 0;
      return fac[n] * (finv[k] * finv[n - k] % LIMIT) % LIMIT;
  }
}

#define debug2(x,y) cout<<"("<<#x<<","<<#y<<") = ("<<(x)<<","<<(y)<<")\n"


int main(){
  COMinit();
  int N,K;cin>>N>>K;
  ll a, b, ans;
  for(int i=1; i<=K; i++){
    a = l_nCr(K-1, i-1);
    //a = COM(K-1, i-1) % LIMIT;
    b = l_nCr(N-K+1, i);
    //b = COM(N-K+1, i) % LIMIT;
    //debug2(a,b);
    ans = a * b % LIMIT;
    cout<<ans<<endl;
  }
}