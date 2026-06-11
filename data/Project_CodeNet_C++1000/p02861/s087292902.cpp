#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
const int INF = 1e9;
ll x[10], y[10];

double dist(ll i, ll j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return pow(dx * dx + dy * dy, 0.5);
}

int main() {
  ll n, cnt = 0;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  double ans = 0;

  rep(i, n) for (int j = i + 1; j < n; ++j) ans += dist(i, j);

  cout << setprecision(16) << ans / n * 2 << endl;
  return 0;
}
