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
  ll n;
  cin >> n;
  vector<ll> cnt(n, 0);
  REP(i, n) {
    ll a;
    cin >> a;
    a--;
    cnt[a]++;
  }
  // s[x] = \sum_{i=0}^{n-1} min(cnt[i],x)
  vector<ll> s(n + 1, 0);
  // s[x+1] = s[x] + (x<cnt[p]を満たすpの個数)
  sort(ALL(cnt));
  REP(x, n) {
    auto it = lower_bound(ALL(cnt), x + 1);
    ll diff = cnt.end() - it;
    s[x + 1] = s[x] + diff;
  }
  FOR(t, 1, n + 1) {
    ll ok = 0, ng = n + 1;
    while (ok + 1 < ng) {
      ll x = (ok + ng) / 2;
      if (t * x <= s[x])
        ok = x;
      else
        ng = x;
    }
    cout << ok << endl;
  }
}