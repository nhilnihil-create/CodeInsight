#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int T)
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << max(max(a*c,a*d),max(b*c,b*d));
}



signed main()
{
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}