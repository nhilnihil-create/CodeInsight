#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,b,c,d;

signed main()
{
  cin >> a >> b >> c >> d;
  int minx = min(a,b);
  int maxx = max(a,b);
  int miny = min(c,d);
  int maxy = max(c,d);
  int res = -1e18-1;
  //cout << res << '\n';
  res = max(res,minx*miny);
  res = max(res,minx*maxy);
  res = max(res,maxx*miny);
  res = max(res,maxx*maxy);
  cout << res;
    return 0;
}
