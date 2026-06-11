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
  string s;
  int k;
  cin >> s >> k;
  char now = s[0];
  bool flag = true;
  REP(i, s.size()) if (s[i] != now) flag = false;
  if (flag) {
    cout << (ll)(s.size() * k / 2) << endl;
    return;
  }
  ll count = 0, j = 1;
  FOR(i, 1, s.size() - 1) {
    if (s[i] == now) {
      j++;
    } else {
      count += j / 2;
      j = 1;
    }
    now = s[i];
  }
  count += j / 2;
  ll ans;
  if (s[0] == s[s.size() - 1]) {
    ll a = 1, b = 1;
    FOR(i, 1, s.size() - 1) {
      if (s[i] == s[i - 1]) a++;
      else
        break;
    }
    RFOR(i, s.size() - 2, 0) {
      if (s[i] == s[i + 1]) b++;
      else
        break;
    }
    ans = (ll)(count) * k - (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
  } else {
    ans = (ll)(count) * k;
  }
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
