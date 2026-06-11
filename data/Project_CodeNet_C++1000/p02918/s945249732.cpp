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
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;

void solve(istream& cin, ostream& cout) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int bad = 0;
  char now = s[0];
  REP(i, n) {
    if (i == 0) continue;
    if (now != s[i]) bad++;
    now = s[i];
  }
  int ans = n - 1 - bad;
  if (2 * k <= bad) ans += 2 * k;
  else
    ans = n - 1;
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif
