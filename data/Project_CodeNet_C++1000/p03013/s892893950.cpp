#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<bool> a(n + 1, 0);
  while (m--) {
    int i;
    cin >> i;
    a[i] = 1;
  }
  vector<ll> c(n + 1);
  c[0] = 1;
  ll M = (ll)1e9 + 7;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      c[i] = 0;
    } else if (i == 1) {
      c[i] = 1;
    } else {
      c[i] = c[i - 2] + c[i - 1];
      c[i] %= M;
    }
  }
  cout << c[n] << '\n';
  return 0;
}
