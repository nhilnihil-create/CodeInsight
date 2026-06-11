#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool isNear(ll x, ll y, ll d)
{
  ll d1 = x*x + y*y;
  d = d * d;
  if (d1 <= d) return true;
  return false;
}

int main()
{
  int n; ll d, a, b;
  cin>>n>>d;
  int ans = 0;
  for (int i=0; i<n; i++)
  {
    cin>>a>>b;
    if (isNear(a,b,d)) ans++;
  }
  cout << ans << '\n';
  return 0;
}