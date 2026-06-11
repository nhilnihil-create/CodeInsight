/*
* @Author: Samson
* @Date:   2018-06-28 21:51:36
* @Last Modified by:   Samson
* @Last Modified time: 2018-06-28 23:03:03
*/
//   @URL : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B

#include<bits/stdc++.h>
#include<algorithm>
#include <queue>
#include<vector>
#include<list>
#include <cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int MAXN = 1e4+10;

vector<int> g[MAXN];
list<int> l;
int in[MAXN],vis[MAXN];
 
void bfs(int s)
{
	queue<int> que;
	que.push(s);
	vis[s] = 1;
	while(que.size())
	{
		int u = que.front();
		que.pop();
		l.push_back(u);
		for(int i = 0; i < g[u].size(); ++i)
		{
			int v = g[u][i];
			--in[v];
			if(!in[v] && !vis[v])
			{
				que.push(v);
				vis[v] = 1;
			}
		}
	}
}

void solve(int n)
{
	for(int u = 0; u < n; ++u)
	{
		if(!in[u] && !vis[u])
			bfs(u);
	}
	for(list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout<<*it<<'\n';
}

int main(void)
{
	ios::sync_with_stdio(false); 
	//cin.tie(0);
	int v,e,s,t;
	cin>>v>>e;
	for(int i = 1; i <= e; ++i)
	{
		cin>>s>>t;
		g[s].push_back(t);
		++in[t];
	}

	solve(v);

	return 0;
}

