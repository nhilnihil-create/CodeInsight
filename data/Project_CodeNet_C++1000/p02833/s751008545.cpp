#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  ll n;
  cin >> n;
  if (n % 2 == 1)
  {
    puts("0");
    return 0;
  }
  ll d = 2;
  ll ans = 0;
  while (d * 5 <= n)
  {
    d *= 5;
    ans += n / d;
  }
  cout << ans << endl;
  return 0;
}