#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 2020202020;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n + 1);
  b[0] = 0;
  rep(i, n) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }
  // rep(i, n + 1) cerr << b[i] << ' ';
  // cerr << endl;

  ll min_cost = INF;
  for (int i = 1; i < n; i++) {
    // cerr << b[i] << ' ' << b[n] - b[i] << endl;
    ll cost = abs(b[i] - (b[n] - b[i]));
    min_cost = min(min_cost, cost);
  }
  cout << min_cost << endl;

  return 0;
}
