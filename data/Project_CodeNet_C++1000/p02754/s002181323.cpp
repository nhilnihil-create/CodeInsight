#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  ll res = n / (a+b)*a;
  ll r = n % (a+b);
  res += min(r, a);
  cout << res << endl;
  return 0;
}
