#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int s, w;
  cin >> s >> w;

  if (w >= s) cout << "unsafe\n";
  else cout << "safe\n";

  return (0);
}