#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
int main() {
  ll x, k, d; cin >> x >> k >> d;
  i128 X = abs(x);
  while (k != 1) {
    ll k2 = k / 2;
    X = abs(X - i128(k2) * d);
    k -= k2;
  }
  cout << ll(abs(X - d)) << endl;
}
