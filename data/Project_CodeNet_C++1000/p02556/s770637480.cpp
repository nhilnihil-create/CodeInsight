#include<bits/stdc++.h>
using namespace std;
 
#define lint long long int

void solve()
{
    int n;cin >> n;
    lint umin = 1e18,umax = -1 * 1e18 , vmin = 1e18 , vmax = -1*1e18; 
    lint ret = LONG_LONG_MIN;
    for(int i=0;i<n;++i)
    {
        lint x,y;cin >> x >> y;
        lint u = x + y;
        lint v = x - y;

        ret = max(ret,u - umin);
        ret = max(ret,umax - u);
        ret = max(ret,v - vmin);
        ret = max(ret,vmax - v);

        umin = min(u,umin);
        umax = max(u,umax);
        vmin = min(v,vmin);
        vmax = max(v,vmax);
    }

    cout << ret << '\n';
}
 
signed main()
{
     int test_cases;test_cases=1;
     //cin >> test_cases;
     while(test_cases --> 0) solve();
}