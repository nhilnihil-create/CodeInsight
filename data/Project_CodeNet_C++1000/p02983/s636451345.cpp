#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll l, r;
  cin >> l >> r;
  ll m = 2019;
  if (r-l >= 2018) {
    cout << 0 << endl;
    return 0;
  }
  
  ll ans = 2019;
  for (ll i = l; i < r; i++) {
    for (ll j = i+1; j <= r; j++) {
      ans = min(ans, i*j%m);
    }
  }

  cout << ans << endl;
  return 0;
}