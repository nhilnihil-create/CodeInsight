#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  if (n >= 10000)
  {
    ans += min(90000, n - 10000 + 1);
  }
  if (n >= 100)
  {
    ans += min(900, n - 100 + 1);
  }
  if (n >= 1)
  {
    ans += min(9, n - 1 + 1);
  }
  cout << ans << endl;
  return 0;
}