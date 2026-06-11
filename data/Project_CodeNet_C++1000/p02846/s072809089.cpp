#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  a1 *= t1;
  a2 *= t2;
  b1 *= t1;
  b2 *= t2;

  if (a1 + a2 == b1 + b2) {
    cout << "infinity" << endl;
    return 0;
  }

  if ((a1 < b1 && a1 + a2 < b1 + b2) || (a1 > b1 && a1 + a2 > b1 + b2)) {
    cout << 0 << endl;
  }
  else {
    ll x1 = abs(a1 - b1), x2 = abs((a1 + a2) - (b1 + b2));
    if (x1 % x2 == 0) cout << (x1 / x2) * 2 << endl;
    else cout << (x1 / x2) * 2 + 1 << endl;
  }


  return 0;
}