#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(int x, int y, vector<int> v)
{
  swap(v[x], v[y]);
  bool res = true;
  for (int i = 1; i < v.size(); ++i) if (v[i] - v[i-1] < 0) res = false;

  return res;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (f(i, j, a)) {
        cout << "YES\n";
        return (0);
      }
    }
  }

  cout << "NO\n";

  return (0);
}
