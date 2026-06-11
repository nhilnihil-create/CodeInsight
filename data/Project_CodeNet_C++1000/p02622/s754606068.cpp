#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

string s, t;
void input() { cin >> s >> t; }
void solve() {
  int ans = 0;
  rep(i, 0, s.size()) ans += (s[i] != t[i]);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}