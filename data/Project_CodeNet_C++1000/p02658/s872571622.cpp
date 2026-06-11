#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull M = 1e18;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

inline void chk(ull a, ull b) {
  if (a > M / b) {
    cout << "-1" << endl;
    exit(0);
  }
}

void solve() {
  ull N;
  cin >> N;
  vector<ull> v(N);
  for (auto &e : v) {
    cin >> e;
    if (e == 0) {
      cout << 0 << endl;
      return;
    }
  }

  ull ans = 1;
  rep(i, 0, N) {
    chk(ans, v[i]);
    ans *= v[i];
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}