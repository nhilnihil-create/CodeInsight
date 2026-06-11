#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long pow_kai(long long a, long long n){//aのn乗を計算します。
  long long x = 1;
  while(n > 0){//全てのbitが捨てられるまで。
    if(n&1){//1番右のbitが1のとき。
      x = x*a;
      x %= mod;
    }
    a = a*a;
    a %= mod;
    n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
  }
  return x;
}


int main() {
  long long N,K;
  cin >> N >> K;
  long long nu;
  vector<long long> ans(K+1);
  for (int i=K; i>=1; i--) {
    nu = K/i;
    ans[i] = pow_kai(nu,N);
    for (int j=2; j>0; j++) {
      if (i*j > K) {
        break;
      }
      ans[i] += mod;
      ans[i] -= ans[i*j];
      ans[i] %= mod;
    }
  }
  
  long long total = 0;
  for (int i=1; i<=K; i++) {
    total += i * ans[i];
    total %= mod;
  }
  
  cout << total << endl;
  
  return 0;
}