#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k, s;
  cin >> n >> k >> s;

  if (s > n) {
    for (int i = 0; i < n; i++) {
      if (i < k) cout << s;
      else cout << 1;

      if (i == n - 1) cout << endl;
      else cout << ' ';
    }
  }
  else {
    const int max_v = 1e9;
    for (int i = 0; i < n; i++) {
      if (i < k) cout << s;
      else cout << max_v;

      if (i == n - 1) cout << endl;
      else cout << ' ';
    }
  }
  return 0;
}