#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  ll n; cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  for (int i=1; i<n; i++) {
    a[i] += a[i-1];
  }
  ll ans = 1LL<<60;
  for (int i=0; i<n; i++) {
    ans = min(ans, abs(a[i]-(a[n-1]-a[i])));
  }
  cout << ans << endl;

  return 0;
}
