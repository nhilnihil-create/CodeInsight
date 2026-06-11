#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> h(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  vector<ll> ans(n, 0);
  for (ll i = 0; i < m; i++)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    ans[a] = max(ans[a], h[b]);
    ans[b] = max(ans[b], h[a]);
  }
  ll cnt = 0;
  for (ll i = 0; i < n; i++)
  {
    cnt += h[i] > ans[i];
  }
  cout << cnt << endl;
}
