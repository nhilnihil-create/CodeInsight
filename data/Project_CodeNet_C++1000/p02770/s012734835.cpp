#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int k, q;
  cin >> k >> q;
  long long d[k];
  for (int i = 0; i < k; i++) {
    cin >> d[i];
  }
  while (q--) {
    long long n, x, m;
    cin >> n >> x >> m;
    long long ans;
    if (n <= k) {
      long long a = x;
      ans = 0;
      for (int i = 0; i < n - 1; i++) {
        if (a % m < (a + d[i]) % m) ans++;
        a += d[i];
      }
    } else {
      ans = n - 1;
      long long dm[k];
      for (int i = 0; i < k; i++) {
        dm[i] = d[i] % m;
        if (!dm[i]) ans -= (n - 2 - i) / k + 1;
      }
      long long an = x;
      for (int i = 0; i < k; i++) {
        an += dm[i] * ((n - 2 - i) / k + 1);
      }
      ans -= an / m - x / m;
    }
    cout << ans << endl;
  }
  return 0;
}