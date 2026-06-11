#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> adjList[200005];
bool visited[200005];
int memo[200005];

int dfs(int src)
{
	int ans = 1;
		
	visited[src] = true;
	for(int i = 0; i < (int)(adjList[src].size()); i++)
	{
		if(visited[adjList[src][i]])
			continue;
		ans += dfs(adjList[src][i]);
	}
	
	memo[src] = ans;
	return ans;
}

int main()
{
	scanf("%d%d", &N, &M);
	
	for(int i = 1; i <= M; i++)
	{
		int Ai, Bi;
		scanf("%d%d", &Ai, &Bi);
		
		adjList[Ai].push_back(Bi);
		adjList[Bi].push_back(Ai);
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i])
			continue;
		dfs(i);
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++)
		ans = max(ans, memo[i]);
	printf("%d", ans);
}