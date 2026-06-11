#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  int x, y, a, b;
  cin >> x >> y;
  b = (y - 2 * x);
  if (b % 2 == 1)
  {
    cout << "No";
    return 0;
  }
  b /= 2;
  a = x - b;
  if (a >= 0 && b >= 0)
    cout << "Yes";
  else
    cout << "No";
}
