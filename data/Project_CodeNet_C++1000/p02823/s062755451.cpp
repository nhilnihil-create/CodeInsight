#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

ll ans(ll n, ll a, ll b)
{
  ll x = b - a;
  if(x % 2)
  {
    return min((a + b - 1) / 2, n + (1 - a - b) / 2);
  }
  else
  {
    return x / 2;
  }
}

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  
  cout << ans(n, a, b) << endl;
  return 0;
}