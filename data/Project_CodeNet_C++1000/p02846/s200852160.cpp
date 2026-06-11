#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  ll ad1 = t1 * a1;
  ll ad2 = t2 * a2;
  ll bd1 = t1 * b1;
  ll bd2 = t2 * b2;

  if (ad1 < bd1 && ad1 + ad2 > bd1 + bd2) {
    ll d1 = bd1 - ad1;
    ll d2 = (ad1 + ad2) - (bd1 + bd2);
    ll num = d1 / d2;
    cout << num * 2 + 1 - (d1 % d2 == 0);
  } else if (bd1 < ad1 && bd1 + bd2 > ad1 + ad2) {
    ll d1 = ad1 - bd1;
    ll d2 = (bd1 + bd2) - (ad1 + ad2);
    ll num = d1 / d2;
    cout << num * 2 + 1 - (d1 % d2 == 0);
  } else if (ad1 + ad2 == bd1 + bd2) {
    cout << "infinity" << endl;
  } else {
    cout << 0 << endl;
  }

#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}