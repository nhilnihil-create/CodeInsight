#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
int main() {
  ll x, k, d; cin >> x >> k >> d;
  i128 X = abs(x);
  while (k) {
    ll k2 = (k + 1) / 2;
    X = abs(X - i128(k2) * d);
    k /= 2;
  }
  cout << ll(X) << endl;
}
