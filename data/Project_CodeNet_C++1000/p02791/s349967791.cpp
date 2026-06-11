#include <bits/stdc++.h>
#define MAX 200005
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int mn = MAX, ans = 0;

  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;

    if (mn > p) {
      mn = p;
      ++ans;
    }
  }

  cout << ans << '\n';

  return (0);
}
