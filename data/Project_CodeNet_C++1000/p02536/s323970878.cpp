#include<bits/stdc++.h>
using namespace std;
int visited[100001]={0};
vector<int> a[100001];
void dfs(int v)
{
    visited[v]=1;
    for(int i=0;i<a[v].size();i++)
    {
        int child=a[v][i];
        if(visited[child]==0)
        {
            dfs(child);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int c,b;
        cin>>c>>b;
        a[c].push_back(b);
        a[b].push_back(c);
    }
    int coun=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
            coun++;
        }
    }
    cout<<coun-1;
}