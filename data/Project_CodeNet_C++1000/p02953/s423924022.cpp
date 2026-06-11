#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<ll> h(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  for (ll i = 0; i < n - 1; i++)
  {
    if (h[i] < h[i + 1])
    {
      h[i + 1]--;
    }
  }
  for (ll i = 0; i < n - 1; i++)
  {
    if (h[i] > h[i + 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
