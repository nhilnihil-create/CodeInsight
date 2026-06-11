#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += b[i] * (b[i] - 1) / 2;
  }

  for (int i = 0; i < n; i++) {
    cout << ans - (b[a[i]] - 1) * b[a[i]] / 2 +
                (b[a[i]] - 2) * (b[a[i]] - 1) / 2
         << endl;
  }
}
