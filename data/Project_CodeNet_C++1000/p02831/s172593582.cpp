#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y)
{
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y)
{
  return x / gcd(x, y) * y;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  return 0;
}