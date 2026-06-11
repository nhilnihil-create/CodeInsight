#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b)
{
  if (a % b == 0)
  {
    return (b);
  }
  else
  {
    return (gcd(b, a % b));
  }
}

int main()
{
  int k;
  cin >> k;

  ll sum = 0;

  for (int i = 1; i <= k; i++)
  {

    for (int j = 1; j <= k; j++)
    {
      for (int l = 1; l <= k; l++)
      {
        ll tmp = gcd(i, j);
        sum += gcd(tmp, l);
      }
    }
  }
  cout << sum;
}
