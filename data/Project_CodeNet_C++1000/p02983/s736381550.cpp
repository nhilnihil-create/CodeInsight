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
  if (r - l > 2020) r = l + 2020;
  ll ans = 2018;
  for(ll i = l; i <= r; i++) {
    for(ll j = i + 1; j <= r; j++) {
      ans = min(ans, i*j%2019);
    }
  }
  cout << ans << endl;
  return 0;
}