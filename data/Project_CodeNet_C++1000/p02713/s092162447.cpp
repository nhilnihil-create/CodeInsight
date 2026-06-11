#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

int main()
{
  int k;
  cin >> k;
  ll ans = 0;
  for (int i = 1; i <= k; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      for (int l = 1; l <= k; l++)
      {
        ans += gcd(i, gcd(j, l));
      }
    }
  }
  cout << ans << endl;
}
