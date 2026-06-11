#include<bits/stdc++.h>

using namespace std;

#define TC ll t; cin >> t; while(t--)
typedef long long ll;
#define mx 100005

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll x,i;
    cin >> x;
    bool vis[mx];
    memset(vis,0,sizeof(vis));
    for(i=2;i<=mx;i++)
    {
        if(vis[i]) continue;
        if(i>=x) break;
        for(ll j=i;j<=mx;j+=i) vis[j]=1;
    }
    cout << i << endl;
    return 0;
}
