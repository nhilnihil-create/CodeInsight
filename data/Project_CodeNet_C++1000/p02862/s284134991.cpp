#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long modpow(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a){
  return modpow(a, MOD - 2);
}
vector<long long> mf;
long long modfact(long long a){
  if (mf.size() > a){
    return mf[a];
  } else {
    if (mf.empty()){
      mf.push_back(1);
    }
    for (int i = mf.size(); i <= a; i++){
      long long next = mf.back() * i % MOD;
      mf.push_back(next);
    }
    return mf[a];
  }
}
long long modbinom(long long a, long long b){
  return modfact(a) * modinv(modfact(b)) % MOD * modinv(modfact(a - b)) % MOD;
}
int main(){
  long long X, Y;
  cin >> X >> Y;
  if ((X * 2 - Y) % 3 != 0){
    cout << 0 << endl;
  } else if ((Y * 2 - X) % 3 != 0){
    cout << 0 << endl;
  } else if (X * 2 - Y < 0){
    cout << 0 << endl;
  } else if (Y * 2 - X < 0){
    cout << 0 << endl;
  } else {
    int A = (X * 2 - Y) / 3;
    int B = (Y * 2 - X) / 3;
    cout << modbinom(A + B, A) << endl;
  }
}