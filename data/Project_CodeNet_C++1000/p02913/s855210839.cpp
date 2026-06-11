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
  string s;
  cin >> n >> s;
  ll ok = 0, ng = n + 1;
  while (ok + 1 < ng) {
    ll m = (ok + ng) / 2;
    map<string, vector<ll>> mp;
    REP(i, n - m + 1) {
      string t = s.substr(i, m);
      mp[t].push_back(i);
    }
    bool pass = false;
    for (auto& x : mp) {
      vector<ll> v = x.second;
      ll l = v[0], r = v[SZ(v) - 1];
      if (l + m - 1 < r) {
        pass = true;
      }
    }
    (pass ? ok : ng) = m;
  }
  cout << ok << endl;
}