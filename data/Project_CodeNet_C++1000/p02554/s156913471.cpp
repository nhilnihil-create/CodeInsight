#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long ans, c = pow(10, 9) + 7, a = 1, b = 1, d = 1;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    a = a * 10 % c;
    b = b * 9 % c;
    d = d * 8 % c;
  }

  ans = (a - (2 * b % c) + d) % c;
  if (ans < 0)
    ans += c;
  cout << ans << endl;
}
