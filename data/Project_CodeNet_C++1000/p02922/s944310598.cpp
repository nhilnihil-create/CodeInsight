#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, y) for (ll i = x; i < y; i++)

int main()
{
  int a, b, c;
  cin >> a >> b;

  for (int i = 1;; i++)
  {
    c = 1 + (a - 1) * i;
    if ((b - 1) % (a - 1) == 0)
    {
      cout << (b - 1) / (a - 1) << endl;
      break;
    }
    else if (c > b)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}