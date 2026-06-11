#include <iostream>
using namespace std;

long long MOD = 1e9 + 7;

long long modPow(long long x, long long a) {
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(long long x) {
  return modPow(x, MOD - 2);
}

long long modPerm(long long n, long long k) {
  long long ret = 1;
  for (long long i = 0; i < k; i++) {
    ret = (ret * (n - i)) % MOD;
  }
  return ret;
}

long long modComb(long long n, long long k) {
  long long a, b;
  a = modPerm(n, k);
  b = modPerm(k, k);
  return (a * modInv(b)) % MOD;
}

int main(){
    long long n, a, b, sum;
    cin >> n >> a >> b;
    sum = modPow(2, n);
    sum -= 1;
    sum -= modComb(n, a);
    sum -= modComb(n, b);
    cout << (MOD * 2 + sum) % MOD;
    return 0;
}