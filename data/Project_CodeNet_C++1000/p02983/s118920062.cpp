#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  ll l,r;
  cin >> l >> r;
  
  if(r - l >= 2019)
  {
    cout << 0 << endl;
    return 0;
  }
  
  ll ans = 2020;
  for(ll i = l; i < r; i++)
  {
    for(ll j = i+1; j <= r; j++)
    {
      if(j % 2019 == 0)
      {
        cout << 0 << endl;
        return 0;
      }
      ans = min(ans,(i*j)%2019); 
    }
  }
  
  cout << ans << endl;
  
}
