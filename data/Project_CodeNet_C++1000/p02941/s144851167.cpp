#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n + n; i++) {
    cin >> (i < n ? a[i] : b[i - n]);
  }
  priority_queue<pair<int, int>> que;
  for (int i = 0; i < n; i++) {
    que.emplace(b[i], i);
  }
  long long ans = 0;
  while (que.size()) {
    int i = que.top().second;
    que.pop();
    int nbr = b[(i - 1 + n) % n] + b[(i + 1) % n];
    if ((b[i] - a[i]) % nbr == 0) {
      ans += (b[i] - a[i]) / nbr;
      b[i] = a[i];
      continue;
    }
    if (nbr >= b[i]) {
      cout << -1 << endl;
      return 0;
    }
    ans += b[i] / nbr;
    b[i] %= nbr;
    if (b[i] < a[i]) {
      cout << -1 << endl;
      return 0;
    }
    que.emplace(b[i], i);
  }
  cout << ans << endl;
  return 0;
}