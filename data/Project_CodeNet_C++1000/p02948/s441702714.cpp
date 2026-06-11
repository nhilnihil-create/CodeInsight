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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> tbl(200000);
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    tbl[a - 1].push_back(b);
  }

  // pair の1つめの要素に従って降順に
  priority_queue<int, vector<int>, less<int>> pq;
  ll ans = 0;
  REP(i, m) {
    EACH(b, tbl[i]) pq.push(b);
    if (pq.empty()) continue;
    ans += pq.top();
    pq.pop();
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
