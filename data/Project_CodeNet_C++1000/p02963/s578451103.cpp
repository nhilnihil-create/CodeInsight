#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t S, x, y;
  cin >> S;
  if (S % 1000000000 == 0)
  {
    x = 0;
    y = S / 1000000000;
  }
  else
  {
    int64_t q = S / 1000000000, r = S % 1000000000;
    y = q + 1;
    x = 1000000000 - r;
  }
  cout << 0 << ' ' << 0 << ' ' << 1000000000 << ' ' << 1 << ' ' << x << ' ' << y << endl;
}
