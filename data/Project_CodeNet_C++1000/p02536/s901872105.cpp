#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+7;
const int M = 1e9+7;

int pre[maxn];

int find(int x)
{
    return x==pre[x]?x:pre[x]=find(pre[x]);
}

signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = 1,x,y; i <= m; i++) 
    {
        cin>>x>>y;
        x = find(x);
        y = find(y);
        pre[x] = y;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) 
    {
        if(i == find(i)) ans++;
    }
    cout<<ans-1<<endl;
    return 0;
}