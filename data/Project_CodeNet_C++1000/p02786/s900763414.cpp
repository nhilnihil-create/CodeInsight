#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll h)
{
  if (h == 1)
  {
    return h;
  }
  return 2 * f(h / 2) + 1;
}

int main()
{
  ll h;
  cin >> h;
  cout << f(h) << endl;
}
