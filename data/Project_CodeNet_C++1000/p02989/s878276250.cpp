#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
using ll = long long;

ll point[MAX];

signed main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;

    ++point[d];
  }

  for (int i = 0; i < MAX; ++i) point[i+1] += point[i];

  int ans = 0;
  for (int i = 1; i < MAX; ++i) {
    ll l = point[i];
    ll r = point[MAX-1] - point[i];

    if (l == r) ++ans;
  }

  cout << ans << '\n';

  return (0);
}
