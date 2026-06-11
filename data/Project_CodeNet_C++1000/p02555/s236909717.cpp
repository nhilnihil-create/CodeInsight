#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll ans[2010];
void solve(int T)
{
    int s;
    cin >> s;
    ans[3]=ans[4]=ans[5]=1;
    for(int i=6;i<=2000;i++)
    {
        ans[i] = (ans[i-1]+ans[i-3])%mod;
    }
    cout << ans[s];
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