#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll h[n];
  rep(i,n) cin >> h[i];
  
  ll max = 0;
  ll maxnum = 0;
  rep(i,n)
  {
    if(h[i] > max)
    {
      max = h[i];
      maxnum = i;
    }
  }
  
  for(int i = maxnum; i < n; i++)
  {
    if(h[i] + 1 < h[maxnum])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  
  for(int i = 0; i < n-1; i++)
  {
    if(h[i] - 1 > h[i+1])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  
}
