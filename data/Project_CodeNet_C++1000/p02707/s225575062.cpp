#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<ll> v(n, 0);
  for (ll i = 0; i < n - 1; i++)
  {
    ll a;
    cin >> a;
    v[a - 1]++;
  }
  for (ll i = 0; i < n; i++)
  {
    cout << v[i] << endl;
  }
}
