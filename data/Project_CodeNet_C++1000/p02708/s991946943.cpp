#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int M = (int) 1e9 + 7;

ll g(ll p) {
  return p * (p + 1) / 2;
}

ll g(ll l, ll r) {
  return g(r) - g(l - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  n++;
  ll sol = 0;
  for (int t = k; t <= n; t++) {
    ll mn = g(0, t - 1);
    ll mx = g(n - t, n - 1);
    sol = (sol + mx - mn + 1) % M;
  }
  cout << sol << "\n";
  return 0;
}
