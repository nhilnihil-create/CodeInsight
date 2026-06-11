#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[200005];
bool vis[200005];
map<int,int>prevcnt;

int ans=-1,tcnt,node;
ll n,k;

void dfs(int u,int cnt,int chk)
{
    vis[u]=true;
    if(chk==1)
    prevcnt[u]=cnt;

    if(cnt==k)
        ans=u;
    for(int v:adj[u])
    {
        if(vis[v]==true&&chk==1)
        {
            node=v;
            return;
        }
        if(vis[v]==true&&chk==2)
        {
            tcnt=cnt+1;
            return;
        }
        dfs(v,cnt+1,chk);
    }
}
void dfs2(int u,int cnt)
{
    if(cnt==k){
       cout<<u<<endl;
       exit(0);
    }
    for(int v:adj[u])
    {
        dfs2(v,cnt+1);
    }
}
int main()
{

    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        adj[i].push_back(x);
    }
    dfs(1,0,1);

    if(ans!=-1) cout<<ans<<endl;
    else
    {
        memset(vis,0,sizeof vis);

        dfs(node,0,2);
        k-=prevcnt[node];

        k%=tcnt;
        dfs2(node,0);
    }
}
