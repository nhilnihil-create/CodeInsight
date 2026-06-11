#include <bits/stdc++.h>
using namespace std;

#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)

string s;
void input() { cin >> s; }

void solve() {
  int ans = 0, cnt = 0;
  rep(i, 0, 3) {
    if (s[i] == 'R')
      cnt++;
    else
      cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
  getchar();
}