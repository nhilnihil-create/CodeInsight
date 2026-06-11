
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;
const long long MOD = 1000000007;

void solve(ll N, ll K) {
  vector<ll> a(N + 1, 0);
  vector<ll> b(N + 1, 0);

  rep(i, N) a.at(i + 1) = a.at(i) + (i + 1);
  b.at(N) = N;
  repr(i, N - 1) b.at(i) = b.at(i + 1) + i;

  ll ans = 0;

  FOR(i, K, N + 2) {
    ans += b.at(N + 1 - i) - a.at(i - 1) + 1 % MOD;
    ans %= MOD;
  }

  cout << ans << endl;
}

int main() {
  ll N;
  scanf("%lld", &N);
  ll K;
  scanf("%lld", &K);
  solve(N, K);
  return 0;
}
