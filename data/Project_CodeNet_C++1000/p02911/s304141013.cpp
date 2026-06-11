#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k, q;
  cin >> n >> k >> q;

  vector<int> a(n, k - q);
  for (int i = 0; i < q; ++i) {
    int p;
    cin >> p;
    --p;

    ++a[p];
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) cout << "Yes\n";
    else cout << "No\n";
  }

  return (0);
}
