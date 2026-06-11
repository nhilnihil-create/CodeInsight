#include <iostream>
using namespace std;

long long MOD = 1000000000 + 7;

long long fctm(long long x) {
  long long result = 1;
  for (long long i = 1; i <= x; i++) {
    result = result * i % MOD;
  }
  return result;
}

long long powm(long long x, long long p) {
  if (p == 0) return 1;
  long long tmp = x * x % MOD;
  if (p % 2 == 0) {
    return powm(tmp, p/2);
  } else {
    return x * powm(tmp, (p-1)/2) % MOD;
  }
}

long long finvm(long long x) {
  long long result = 1;
  for (long long i = 1; i <= x; i++) {
    result = result * powm(i, MOD-2) % MOD;
  }
  return result;
}

int main() {
  long long X, Y;
  cin >> X >> Y;
  if ((2*Y-X) % 3 != 0 || (2*X-Y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long p = (2*Y-X)/3, q = (2*X-Y)/3;
  if (p < 0 || q < 0) {
    cout << 0 << endl;
    return 0;
  }
  long long res = (fctm(p+q)*finvm(p) % MOD) * finvm(q) % MOD;
  cout << res << endl;
  return 0;
}