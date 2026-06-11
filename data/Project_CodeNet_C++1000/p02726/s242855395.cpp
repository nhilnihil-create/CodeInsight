#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, x, y;
  cin >> n >> x >> y;

  map<int,int> mp;

  for (int start = 1; start <= n; ++start) {
    for (int goal = start+1; goal <= n; ++goal) {
      int k = min(goal - start, abs(start - x) + abs(goal - y) + 1);
      ++mp[k];
    }
  }

  for (int i = 1; i < n; ++i) cout << mp[i] << '\n';

  return (0);
}
