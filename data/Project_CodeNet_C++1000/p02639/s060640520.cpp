#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int ans = 0;
  rep(i, 5)
  {
    int x;
    cin >> x;
    if (x == 0)
      ans = i + 1;
  }
  cout << ans << endl;
  return 0;
}