#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const int MOD = 2019;
const int INF = 100100100;

int main() {
  ll l, r;
  cin >> l >> r;
  ll c = r - l;
  int m = INF;
  for (ll i = l; i <= l + c; i++) {
    for (ll j = i + 1; j <= l + c; j++) {
      if (i == j) {
        continue;
      }
      int mod = (i * j) % MOD;
      m = min(m, mod);
      if (m == 0) {
        cout << m << endl;
        return 0;
      }
    }
  }
  cout << m << endl;
  return 0;
}
