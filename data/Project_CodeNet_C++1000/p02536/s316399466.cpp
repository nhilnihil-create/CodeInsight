#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 100005;
int n,m;
int fa[N];

int getfa(int x)
{
    if(x==fa[x])
        return x;
    return fa[x] = getfa(fa[x]);
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
    for(int i = 1; i <= m; ++i){
        int u,v;
        cin >> u >> v;
        int fu = getfa(u);
        int fv = getfa(v);
        fa[fu] = fv;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(fa[i]==i)
            ++ans;
    }
    cout << ans - 1 << endl;
}
