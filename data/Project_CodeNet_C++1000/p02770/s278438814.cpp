#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K, Q;
vector<ll> D;

int main() {
  cin >> K >> Q;
  D.resize(K);
  for (ll i = 0; i < K; ++i) {
    cin >> D[i];
  }
  for (ll q = 0; q < Q; ++q) {
    ll n, x, m;
    cin >> n >> x >> m;
    ll y = x;
    ll res = n - 1;
    for (ll i = 0; i < K; ++i) {
      ll d = D[i] % m;
      ll l = (n - 2 - i) < 0 ? 0 : (n - 2 - i) / K + 1;
      y += d * l;
      if (d == 0) res -= l;
    }
    res -= (y / m) - (x / m);
    cout << res << endl;
  }
  return 0;
}
