#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int X;
  cin >> X;
  rep(i, X + 1)
  {
    int rest = X - i * 100;
    if (0 <= rest && rest <= 5 * i) // 100n <= X <= 100n + 5nであればいい
    {
      cout << 1 << endl;
      return 0;
    }
    if (rest < 0)
      break;
  }
  cout << 0 << endl;
  return 0;
}