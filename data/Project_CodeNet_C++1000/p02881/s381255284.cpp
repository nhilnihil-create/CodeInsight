#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll x, y;
  ll ans = 1e13;
  for(int i = 1; i <= sqrt(n); i++)
  {
    if(n % i == 0)
    {
      x = i;
      y = n / i;
      
      if( ((x-1) + (y-1)) < ans )
      {
        ans = (x-1) + (y-1);
      }
    }
  }
  
  cout << ans << endl;
}
