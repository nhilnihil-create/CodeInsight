#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int x, ans;
  rep(i, 0, 5) {
    cin >> x;
    if (x == 0) ans = i + 1;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}