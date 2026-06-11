#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll n, d, a;
  cin >> n >> d >> a;
  vector<ll> x(n), h(n);
  REP(i, n) {
    cin >> x[i] >> h[i];
    h[i] = (h[i] + a - 1) / a;
  }
  vector<ll> ord(n), cnt(n + 5, 0);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](ll i, ll j) { return x[i] < x[j]; });

  ll ans = 0;
  REP(i, n) {
    ll j = ord[i];
    // h[j] - cnt[i]回攻撃
    ll t = max(h[j] - cnt[i], 0LL);
    ans += t;
    // x[j] + 2d まで攻撃可能
    ll ok = -1, ng = n;
    while (ok + 1 < ng) {
      ll m = (ok + ng) / 2;
      (x[ord[m]] <= x[j] + 2 * d ? ok : ng) = m;
    }
    cnt[i] += t;
    cnt[ng] -= t;
    cnt[i + 1] += cnt[i];
  }
  cout << ans << endl;
}