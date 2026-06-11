#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll a, b, n;
  cin >> a >> b >> n;

  ll s = min(b - 1, n);
  ll ans = floor(a * s / b) - a * floor(s / b);
  cout << ans << endl;
}
