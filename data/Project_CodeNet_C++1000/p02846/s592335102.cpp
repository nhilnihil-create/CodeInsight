#include "bits/stdc++.h"
using namespace std;
typedef long long int64;

int main() {
  int64 T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  int64 i1 = (A1 - B1) * T1;
  int64 i2 = (A2 - B2) * T2;

  if (i1 + i2 == 0) {
    cout << "infinity\n";
    return 0;
  }
  int s1 = (i1 > 0) ? 1 : -1;
  int s2 = (i2 > 0) ? 1 : -1;
  if (s1 * s2 > 0) {
    cout << "0\n";
    return 0;
  }
  int64 p = i1 + i2;
  if (p * s1 > 0) {
    cout << "0\n";
    return 0;
  }
  int64 toge = i1;
  p = abs(p);
  toge = abs(toge);
  int64 tmp = toge / p;
  int64 ans = abs(tmp) * 2 + 1;
  if (toge % p == 0) ans--;
  cout << ans << "\n";
  
  return 0;
}
