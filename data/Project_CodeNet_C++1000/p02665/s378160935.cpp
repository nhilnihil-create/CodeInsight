#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  int n;
  cin >> n;
  vector<llint> a(n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  vector<llint> b(n + 2, 0);
  for (int i = 0; i <= n; i++) {
    b[i + 1] = b[i] + a[i];
  }

  llint now = 1, ans = 0;
  for (int i = 0; i <= n; i++) {
    llint c = now - a[i];
    if (c < 0) {
      cout << -1 << endl;
      return 0;
    }
    ans += a[i] + c;
    llint next = 2 * c;
    llint m = b.back() - b[i] - a[i];
    if (m < next) {
      next = m;
    }
    now = next;
  }

  cout << ans << endl;

  return 0;
}
