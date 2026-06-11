#include <bits/stdc++.h>

#define rep(x, n) for(int i = x; i < (n); ++i)

using namespace std;

int main(void)
{
  int l, r, d;
  cin >> l >> r >> d;
  int res = 0;
  rep(l, r + 1) if (i % d == 0) ++res;
  cout << res << endl;
}