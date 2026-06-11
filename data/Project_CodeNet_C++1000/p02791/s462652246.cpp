#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = (int)1e9, ans = 0;
  while (n--) {
    int p;
    cin >> p;
    if (p <= m) ans++;
    m = min(m, p);
  }
  cout << ans;
  return 0;
}
