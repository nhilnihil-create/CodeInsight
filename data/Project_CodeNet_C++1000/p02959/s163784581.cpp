#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll t[n+1], y[n];
  rep(i,n+1) cin >> t[i];
  rep(i,n) cin >> y[i];
  
  ll ans = 0;
  rep(i,n)
  {
    if(y[i] > t[i])
    {
      ans += t[i];
      y[i] -= t[i];
      if(y[i] > t[i+1])
      {
        ans += t[i+1];
        t[i+1] = 0;
      }else{
        ans += y[i];
        t[i+1] -= y[i];
      }
    }else{
      ans += y[i];
    }
  }
  
  cout << ans << endl;
}