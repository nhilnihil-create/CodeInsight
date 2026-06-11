#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<bool> ng(n, true);
  while (k--) {
    int d;
    cin >> d;
    while (d--) {
      int a;
      cin >> a;
      a--;
      ng[a] = false;
    }
  }
  int ans = 0;
  for (auto&& e : ng) {
    ans += e;
  }
  cout << ans << '\n';
  return 0;
}
