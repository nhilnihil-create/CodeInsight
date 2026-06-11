#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];

  int ia = 0, ib = 0;
  long long sum = 0;
  while (ia < n && sum < k) sum += a[ia++];
  if (sum > k) sum -= a[--ia];
  
  int res = ia;
  while (ib < m) {
    sum += b[ib++];
    while (ia > 0 && sum > k) sum -= a[--ia];
    if (sum <= k) res = max(ia + ib, res);
  }
  cout << res << endl;
}
