#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int s, w;
  string ans;
  cin >> s >> w;
  if (w >= s) ans = "unsafe";
  else ans = "safe";
  cout << ans << endl;

  return 0;
}
