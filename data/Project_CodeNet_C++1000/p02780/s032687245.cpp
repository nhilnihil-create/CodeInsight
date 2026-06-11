#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

int main() {
  ll n, k;
  ld ans = 0, cnt = 0;
  cin >> n >> k;
  vector<ll> p(n);
  vector<ld> e(n);
  rep(i, n) cin >> p[i], e[i] = (1 + p[i]) / 2.0;
  rep(i, k) cnt += e[i];
  ans = max(ans, cnt);
  for (int i = k; i < n; ++i) {
    cnt += e[i] - e[i - k];
    ans = max(ans, cnt);
  }

  printf("%.10Lf", ans);
  return 0;
}
