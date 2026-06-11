#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000 * 100 + 11;
vector<int > a[MAX];
vector<bool > vis(MAX);
int n, m;
int res = 0, curr = 0;

void dfs(int currNode)
{
	if(vis[currNode]) 
	{
		return;
	}
	
	curr++;
	vis[currNode] = true;
	for(auto it: a[currNode]){
		dfs(it);
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x].push_back(y);
		a[y].push_back(x);	
	}			
	
	for(int i = 0; i < n; i++)
	{
		dfs(i);
		res = max(res, curr);
		curr = 0;
	}
	
	cout << res;
	return 0;
}
