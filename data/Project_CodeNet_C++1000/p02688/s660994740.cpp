#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  set<int> s;

  cin >> n >> k;

  while (k --> 0) {
    int d;
    cin >> d;

    for (int i = 0; i < d; ++i) {
      int a;
      cin >> a;

      s.emplace(a);
    }
  }

  cout << n - s.size() << '\n';

  return (0);
}
