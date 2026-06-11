#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int m = 50;
  while (m-- && k--) {
    vector<int> b(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int l = i - a[i];
      int r = i + a[i];
      l = max(l, 0);
      r = min(r, n - 1);
      b[l]++;
      b[r + 1]--;
    }
    for (int i = 0; i < n; i++) {
      b[i + 1] += b[i];
      a[i] = b[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}