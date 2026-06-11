#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, m, p, penalty, ans;
string s;

int main() {
  cin >> n >> m;
  int ans;
  vector<bool> solved(n, false);
  vector<int> wa(n, 0);
  rep (i, m) {
    cin >> p >> s;
    p--;
    if (s == "AC") solved[p] = true;
    else if (!solved[p]) wa[p]++;
  }
  ans = 0;
  rep (i, n) {
    if (solved[i]) {
      ans++;
      penalty += wa[i];
    }
  }
  cout << ans << " " << penalty << endl;
  return 0;
}
