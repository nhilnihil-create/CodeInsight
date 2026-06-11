#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);
  vector<bool> can(n, false);
  rep(i, n - 1) {
    if (h.at(i + 1) - h.at(i) <= 0) {
      can.at(i) = true;
    }
  }
  int res = 0;
  int cnt = 0;
  rep(i, n) {
    if (can.at(i)) {
      cnt++;
    } else {
      res = max(res, cnt);
      cnt = 0;
    }
  }
  cout << res << endl;
  return 0;
}
