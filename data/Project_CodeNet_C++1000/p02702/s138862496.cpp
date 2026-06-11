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

const ll MOD = 2019;
map<int, int> mp;

void solve(istream& cin, ostream& cout) {
  string s;
  cin >> s;
  REVERSE(s);
  mp.clear();
  int n = s.size();
  int mod = 0, p = 1;
  int ans = 0;
  mp[0]++;
  REP(i, n) {
    mod = (mod + (s[i] - '0') * p) % MOD;
    mp[mod]++;
    p = p * 10 % MOD;
  }
  ans = 0;
  REP(i, MOD) {
    // mp[i] combination 2
    if (mp[i] >= 2) ans += mp[i] * (mp[i] - 1) / 2;
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
