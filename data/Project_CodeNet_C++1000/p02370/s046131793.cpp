#include<bits/stdc++.h>
using namespace std;
vector<int> node[10010];
bitset<10010> vis;
int n,m;
void dfs(int k)
{
	vector<int>::iterator v;
	if(vis[k])
		return ;
	cout<<k<<endl;
	vis[k]=1;
	v=node[k].begin()+1;
	if(v==node[k].end())
		return ;
	for(; v!=node[k].end(); ++v)
	{
		node[*v][0]--;
		if(node[*v][0]==0)
			dfs(*v);
	}
	return ;
}
int main()
{
	cin>>n>>m;
	for(int i=0; i<n; ++i)
		node[i].push_back(0);
	for(int i=1; i<=m; ++i)
	{
		int r1,r2;
		cin>>r1>>r2;
		node[r2][0]++;
		node[r1].push_back(r2);
	}
	for(int i=0; i<n; ++i)
		if(node[i][0]==0)
			dfs(i);
	return 0;
}
