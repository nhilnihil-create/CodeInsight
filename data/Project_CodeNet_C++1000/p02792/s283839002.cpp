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

  vector<vector<ll>> cnt(10, vector<ll>(10, 0));

  FOR(i, 1, n + 1) {
    string s = to_string(i);
    cnt[s[0] - '0'][s[SZ(s) - 1] - '0']++;
  }

  ll ans = 0;
  FOR(i, 1, 10) FOR(j, 1, 10) { ans += cnt[i][j] * cnt[j][i]; }
  cout << ans << endl;
}