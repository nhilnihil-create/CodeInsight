/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<int> v[100001];
bool vis[100001];
void dfs(int x)
{
    if(vis[x]) return ;
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(!vis[v[x][i]]) dfs(v[x][i]);
    }
}
int32_t main()
{
    int n,i,m,j,k,l;
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=m;i++)
    {
        cin>>j>>k;
        v[j].push_back(k);
        v[k].push_back(j);
    }
    l=0;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            l++;
            dfs(i);
        }
    }
    cout<<l-1;
    return 0;
}
