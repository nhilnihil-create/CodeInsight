#include <bits/stdc++.h>
using namespace std;

int main()
{
  long double a, b;
  cin >> a >> b;
  for (long double n = 1; n < 10000; n++)
  {
    if (floor(n * 0.08) == a && floor(n * 0.1) == b)
    {
      cout << n << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}