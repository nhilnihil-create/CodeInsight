#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

int main()
{
  ll n;
  cin >> n;
  
  map<ll,ll> a, b;

  REP(i, n)
  {
    ll h;
    cin >> h;
    a[i+h+1]++;
    b[i-h+1]++;
  }
  ll ans = 0;
  for(auto itr : a)
  {
    ans += b[itr.first] * itr.second;
  }
  
  cout << ans << endl;
  return 0;
}