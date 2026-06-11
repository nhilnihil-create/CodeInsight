#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> reds(a);
  vector<int> greens(b);
  priority_queue<int> no_colors;
  int tmp;
  REP(i, a) { cin >> reds[i]; }
  REP(i, b) { cin >> greens[i]; }
  REP(i, c) {
    cin >> tmp;
    no_colors.push(tmp);
  }
  sort(ALL(reds), greater<int>());
  sort(ALL(greens), greater<int>());
  REP(i, x) { no_colors.push(reds[i]); }
  REP(i, y) { no_colors.push(greens[i]); }
  ll ans = 0;
  REP(i, x + y) {
    ans += no_colors.top();
    no_colors.pop();
  }
  cout << ans << endl;
}