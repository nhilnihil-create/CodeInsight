#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> h(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> h[i];
  }

  sort(h.begin(), h.end());

  ll ans = 0;
  for (ll i = 0; i < n - k; i++)
  {
    ans += h[i];
  }
  cout << ans << endl;
}
