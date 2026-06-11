#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m)
{
  return m == 0 ? n : gcd(m, n % m);
}
int main()
{
  int x;
  cin >> x;
  cout << 360 / gcd(x, 360);
  return 0;
}
