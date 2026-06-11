#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int main() {
  long long t1, t2, a1, a2, b1, b2, ma, mb;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  if (a1 < b1) {
    swap(a1, b1);
    swap(a2, b2);
  }
  ma = a1 * t1 + a2 * t2;
  mb = b1 * t1 + b2 * t2;
  if (ma == mb) {
    cout << "infinity\n";
  } else if (ma > mb) {
    cout << "0\n";
  } else {
    long long l = (a1 - b1) * t1, r = mb - ma;
    cout << (l / r) * 2 + ((l % r) != 0 ? 1 : 0) << '\n';
  }
  return 0;
}
