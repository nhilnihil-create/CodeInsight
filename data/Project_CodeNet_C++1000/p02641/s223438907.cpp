#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  int x, n, a;
  cin >> x >> n;
  map<string, int> p;
  rep(i, n)
  {
    cin >> a;
    p[to_string(a)] = 1;
  }
  if (p[to_string(x)] == 0)
  {
    cout << x;
    return 0;
  }
  rep(i, 101)
  {
    if (p[to_string(x - i)] == 0)
    {
      cout << x - i;
      return 0;
    }
    if (p[to_string(x + i)] == 0)
    {
      cout << x + i;
      return 0;
    }
  }
}
