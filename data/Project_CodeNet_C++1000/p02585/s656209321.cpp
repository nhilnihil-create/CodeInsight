#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

void solve(istream& cin, ostream& cout) {
  int n, k;
  cin >> n >> k;
  vector<int> c(n), p(n);
  REP(i, n) cin >> p[i], p[i]--;
  REP(i, n) cin >> c[i];

  ll ans = -LINF;

  auto update = [&](int i) {
    int v = i;
    ll cycle_sum = 0;
    int cycle_cnt = 0;

    while(true) {
      cycle_cnt++;
      cycle_sum += c[i];
      i = p[i];
      if (i == v) break;
    }

    ll now = 0;
    int cnt = 0;

    while(true) {
      cnt++;
      now += c[v];

      if (cnt > k) break;

      int num = (k - cnt) / cycle_cnt;
      ll score = now + max(0ll, cycle_sum) * num;
      ans = max(ans, score);

      v = p[v];
      if (v == i) break;
    }
  };
  REP(i, n) update(i);
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
