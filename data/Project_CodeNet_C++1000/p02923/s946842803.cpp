#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll h[n];
  rep(i,n) cin >> h[i];
  
  ll ans = 0, maxans = 0;
  for(ll i = 0; i < n; i++)
  {
    for(ll j = i; j < n-1; j++)
    {
      if(h[j] >= h[j+1])
      {
        ans++;
      }
      else 
      {
        break;
      }
    }
    if(ans > maxans){
      maxans = ans;
    }
    if(maxans >= n-i)
      break;
    ans = 0;
  }
  
  cout << maxans << endl;
}