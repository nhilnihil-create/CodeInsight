#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int a, b = 0, c;
  cin >> a >> c;
  string ans = "No";
  while (a >= 0) {
    if (a * 2 + b * 4 == c) {
      ans = "Yes";
      break;
    }
    a--;
    b++;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}