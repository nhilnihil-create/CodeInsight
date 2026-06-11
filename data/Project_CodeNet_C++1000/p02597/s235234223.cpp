#include <bits/stdc++.h>

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;
int N;
string s;
void input() { cin >> N >> s; }
void solve() {
  int a = 0, b = 0, ans;
  rep(i, 0, N) if (s[i] == 'R') a++;
  ans = max(a, b);
  rep(i, 0, s.size()) {
    if (s[i] == 'R')
      a--;
    else
      b++;
    int now = max(a, b);
    ans = min(ans, now);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}