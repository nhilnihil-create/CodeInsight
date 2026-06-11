#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  const ll LIMIT = 1e18;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }

  ll sum = a[0];
  for (int i = 1; i < n; i++)
  {
    if (a[i] > LIMIT / sum)
    {
      cout << -1 << endl;
      return 0;
    }
    sum *= a[i];
  }
  cout << sum << endl;
}
