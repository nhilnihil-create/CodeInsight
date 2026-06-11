#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10010];
int vis[10010];
int cnt=0,flag;
stack<int>st;
void dfs(int s)
{
    int i,j,u;
    vis[s]=1;
    for(i=0;i<adj[s].size();i++)
    {
        u=adj[s][i];
        if(vis[u]==0)
        {
            dfs(u);
        }
    }
    vis[s]=2;
    st.push(s);
}
void cl()
{
    for(int i=0;i<=10000;i++)
    {
        vis[i]=0;
    }
}
int main()
{
    int n,m,a,b,i,u;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cl();
    for(i=n-1;i>=0;i--)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }

        while(!st.empty())
        {
            u=st.top();
            printf("%d\n",u);
            st.pop();
        }

}

