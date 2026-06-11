#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int sum = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum ^= a[i];
  }

  for (int i = 0; i < n; ++i) cout << (sum ^ a[i]) << (i == n-1 ? '\n' : ' ');

  return (0);
}
