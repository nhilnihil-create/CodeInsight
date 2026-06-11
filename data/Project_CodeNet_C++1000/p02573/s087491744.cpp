#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
bool vis[200005];
vector<int> fr[200005];
void dfs(int a)
{
    vis[a]=true;
    sum++;
    for(int i=0;i<fr[a].size();++i)
        if(!vis[fr[a][i]])
            dfs(fr[a][i]);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        if(find(fr[x].begin(),fr[x].end(),y)==fr[x].end())
            fr[x].push_back(y);
        if(find(fr[y].begin(),fr[y].end(),x)==fr[y].end())
            fr[y].push_back(x);
    }
    for(int i=0;i<200005;++i)
            vis[i]=false;
    int ans=-1;
    for(int i=1;i<=n;++i)
        if(!vis[i])
            {
                dfs(i);
                ans=max(ans,sum);
                sum=0;
            }
    cout<<ans;
    return 0;
}
