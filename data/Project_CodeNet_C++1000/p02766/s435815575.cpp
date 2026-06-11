#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k;
  cin >> n >> k;
  ll ans = 1;

  while (n / k)
  {
    ans++;
    n /= k;
  }
  cout << ans << endl;
}
