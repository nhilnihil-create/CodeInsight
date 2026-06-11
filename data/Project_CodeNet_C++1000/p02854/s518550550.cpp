#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for(ll &x:a) cin >> x;
  for(int i=1; i<n; ++i) 
  a[i]+=a[i-1];
  ll ans = a[n-1];
  for(int i=0; i<n-1; ++i) 
    ans = min(ans, abs(a[n-1] - 2*a[i]));
  cout << ans;
  return 0;
}