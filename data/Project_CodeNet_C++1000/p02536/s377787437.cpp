#include<bits/stdc++.h>
using namespace std;
bool visited[100010];
vector<int> v[100010];
int n;
void dfs(int node)
{
    visited[node]=true;
    for(int i=0;i<v[node].size();i++)
    {
    	if(visited[v[node][i]]==false)
            dfs(v[node][i]);
    }
}
int main()
{
    int m,k,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
	{
        cin>>a>>b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    }
    int block=0;
    for(int j=1;j<=n;j++)
	{
        if(visited[j]==false)
		{
            dfs(j);
            block++;
        }
    } 
    cout<<block-1<<endl; 
    return 0;
}
