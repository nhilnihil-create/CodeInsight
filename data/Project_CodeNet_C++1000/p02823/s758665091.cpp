#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, a, b;
  cin >> n >> a >> b;
  if(a == b)
    cout << 0 << endl;
  else
  {
    long long temp = abs(a - b);
    if(temp & 1)
    {
      long long x = min(a - 1LL, b - 1LL);
      long long y = min(n - a, n - b);
      cout << min(x, y) + 1 + (abs(b - a) >> 1) << endl;
    }
    else
    {
      cout << (temp >> 1) << endl;
    }
  }
  return 0;
}