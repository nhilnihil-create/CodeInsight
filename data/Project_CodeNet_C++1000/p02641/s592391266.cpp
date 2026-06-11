#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)
#define repr(i, ss, ee) for (int i = (ss); i >= (ee); --i)

void solve() {
  int x, N;
  cin >> x >> N;
  if (N == 0) {
    cout << x << endl;
    return;
  }

  vector<bool> v(102, true);
  int a;
  rep(i, 0, N) {
    cin >> a;
    v[a] = false;
  }

  using P = pair<int, int>;
  vector<P> ans;
  rep(i, x, v.size()) {
    if (v[i]) {
      ans.emplace_back(abs(i - x), i);
      break;
    }
  }
  repr(i, x, 0) {
    if (v[i]) {
      ans.emplace_back(abs(i - x), i);
      break;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.front().second << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}