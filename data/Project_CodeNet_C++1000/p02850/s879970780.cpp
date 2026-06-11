#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
vector<pair<int,int>> v[100005];
int in[100005];
int ans[100005];
void dfs(int u,int fa,int c,int mx)
{
    for(int i=0;i<v[u].size();i++)
    {
        int j=v[u][i].first;
        if(j==fa) continue;
        ans[v[u][i].second]=c;
        c=(c+1)%mx;
        dfs(j,u,c,mx);
    }
}
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        in[a]++;in[b]++;
    }
    int root=0,mx=0;
    for(int i=1;i<=n-1;i++)
    {
        if(in[i]>mx)
        {
            root=i;
            mx=in[i];
        }
    }
    dfs(root,-1,0,mx);
    cout<<mx<<endl;
    for(int i=1;i<=n-1;i++)
        cout<<ans[i]+1<<endl;
    return 0;
}
