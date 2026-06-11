#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll x;
  cin >> x;

  for (int a = -118; a <= 119; a++)
  {
    for (int b = -119; b <= 118; b++)
    {
      if ((a * a * a * a * a) - (b * b * b * b * b) == x)
      {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
}