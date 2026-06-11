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
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  REP(j, k) {
    vector<int> s(n + 1, 0);
    REP(i, n) {
      // 累積和の左右
      int l = max(0, i - a[i]);
      int r = min(i + a[i] + 1, n);
      s[l]++;
      s[r]--;
    }
    // 累積和をとる
    REP(i, n) s[i + 1] += s[i];
    // 末尾のゴミを排除
    s.pop_back();
    // 処理前後で変化がなければ終了
    if (a == s) break;
    // そうでなければ次のステップへ
    a = s;
  }
  REP(i, n) {
    cout << a[i] << " ";
  }
  cout << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
