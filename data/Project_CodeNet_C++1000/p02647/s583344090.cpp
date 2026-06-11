#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(n + 1);
  while (k--) {
    for (int i = 0; i <= n; i++) b[i] = 0;
    for (int i = 0; i < n; i++) {
      int from = max(i - a[i], 0);
      int to = min(i + a[i], n - 1);
      b[from] += 1;
      b[to + 1] -= 1;
    }
    bool changed = false;
    for (int i = 0; i < n; i++) {
      changed |= (a[i] != b[i]);
      a[i] = b[i];
      b[i + 1] += b[i];
    }
    if (!changed) break;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << '\n';
  return 0;
}
