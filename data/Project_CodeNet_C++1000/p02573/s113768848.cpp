#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
using namespace std;

int n,m;
vector<int> a[200005];
int vis[200005];
int sz ;
void dfs(int i)
{
    sz++;
    vis[i] = 1;
    for(int t : a[i]){
        if(!vis[t]){
            dfs(t);
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans = 0;
    for(int i=1; i<=n; ++i){
        sz = 0;
        if(!vis[i]){
            dfs(i);
            ans = max(ans,sz);
        }
    }
    printf("%d\n",ans);
    return 0;
}

