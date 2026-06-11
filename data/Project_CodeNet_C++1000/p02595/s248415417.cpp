#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int n,d; cin >> n >> d;
  ll x,y,cnt=0; double p;

  for(int i=0; i<n; ++i)
  {
    cin >> x >> y;
    p = sqrt(x*x + y*y);
    if(p<=d) ++cnt;
  }
  cout << cnt << endl;
}