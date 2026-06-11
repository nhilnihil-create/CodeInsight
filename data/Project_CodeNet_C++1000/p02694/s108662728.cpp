#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll x;
  cin >> x;
  ll dep = 100;
  ll ans = 0;
  while (x > dep)
  {
    dep += dep / 100;
    ans++;
  }
  cout << ans << endl;
}
