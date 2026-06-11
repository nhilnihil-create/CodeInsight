#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve(int T)
{
    int n;
    cin >> n;
    ll _10=1,_9=1,_8=1;
    for(int i=1;i<=n;i++)
    {
        _10 = _10*10%mod;
        _9 = _9*9%mod;
        _8 = _8*8%mod;
    }
    cout << ((_10-2*_9%mod+mod)%mod+_8)%mod;
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