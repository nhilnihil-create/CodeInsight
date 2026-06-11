#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int k, q;
  cin >> k >> q;
  vector<int> d(k);
  for (int i = 0; i < k; i++) 
    cin >> d[i];
  
  for (int i = 0; i < q; i++) {
    int n, x, m;
   	cin >> n >> x >> m;
    
    vector<int> a(k), b(k);
    int eq = d[0] % m == 0;
    b[0] = d[0] % m;
    for (int j = 1; j < k; j++) {
      b[j] = b[j - 1] + d[j] % m;
      a[j] = a[j - 1] + b[j] / m;
      b[j] = b[j] % m;
      if (d[j] % m == 0) eq++;
    }
    
    int rounds = (n - 1) / k;
    long long sa = 1LL * a.back() * rounds;
    long long sb = x % m + 1LL * b.back() * rounds;
    if ((n - 1) % k > 0) {
      sa += a[(n - 1) % k - 1];
      sb += b[(n - 1) % k - 1];
    }
    sa += sb / m;
 
    int ans = n - 1 - sa - eq * rounds;
    for (int j = 0; j < (n - 1) % k; j++)
      if (d[j] % m == 0) ans--;
    cout << ans << '\n';
  }
 
  return 0;
}