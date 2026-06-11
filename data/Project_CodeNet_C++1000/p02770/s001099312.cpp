#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int k, q;
  cin >> k >> q;
  vector<long long> d(k);
  for (int i = 0; i < k; i++) cin >> d[i];
  while (q--) {
    long long n, x, m;
    cin >> n >> x >> m;
    long long tot = 0;
    x %= m;
    long long last = x;
    for (int i = 0; i < k; i++) {
      long long cnt = (n - 1) / k + ((n - 1) % k > i);
      if (d[i] % m == 0) {
        tot += cnt;
      }
      last += (d[i] % m) * cnt;
    }
    tot += last / m - x / m;
    cout << n - 1 - tot << '\n';
  }
  return 0;
}