#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k, q;
  cin >> n >> k >> q;
  vector<ll> member(n, 0);
  for (ll i = 0; i < q; i++)
  {
    ll a;
    cin >> a;
    member[a - 1]++;
  }
  for (ll i = 0; i < n; i++)
  {
    if (member[i] + k - q > 0)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}
