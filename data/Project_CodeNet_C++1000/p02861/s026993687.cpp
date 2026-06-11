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
  iota(v.begin(), v.end(), 0);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  double ans = 0;
  do {
    rep(j, n - 1) ans += dist(v[j], v[j + 1]);
  } while (next_permutation(v.begin(), v.end()));
  int t = 1;
  for (int i = 2; i <= n; ++i) t *= i;

  cout << setprecision(16) << ans / t << endl;
  return 0;
}
