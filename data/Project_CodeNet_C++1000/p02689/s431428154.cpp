#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  vector<bool> good(n, true);
  for (auto&& e : h) {
    cin >> e;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (h[a] == h[b]) {
      good[a] = false;
      good[b] = false;
    } else if (h[a] > h[b]) {
      good[b] = false;
    } else {
      good[a] = false;
    }
  }
  int ans = 0;
  for (auto&& e : good) {
    ans += e;
  }
  cout << ans << '\n';
  return 0;
}
