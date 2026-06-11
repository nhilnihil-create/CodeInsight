#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  ll amari = (n % (a + b));
  ll ans = (n / (a + b)) * a;
  if (amari > a)
  {
    ans += a;
  }
  else
  {
    ans += amari;
  }
  cout << ans << endl;
}