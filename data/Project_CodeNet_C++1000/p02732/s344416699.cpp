#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll combination(ll n)
{
  if (n < 0)
  {
    return 0;
  }

  return n * (n - 1) / 2;
}

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    v[a[i] - 1]++;
  }
  ll all = 0;
  for (int i = 0; i < n; i++)
  {
    all += combination(v[i]);
  }

  for (int i = 0; i < n; i++)
  {
    cout << all - (v[a[i] - 1] - 1) << endl;
  }
}
