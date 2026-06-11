/*
* @Author: Samson
* @Date:   2018-06-14 09:42:05
* @Last Modified by:   Samson
* @Last Modified time: 2018-06-14 10:06:32
*/
//   @URL : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B
#include<bits/stdc++.h>
#include<algorithm>
#include <cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int MAXN = 1e3+10;

int a[MAXN][MAXN],n,d[MAXN],color[MAXN];

void dijkstra()
{
	memset(color,0,sizeof color);
	memset(d,INF,sizeof d);
	int s = 0,u,minv;
	d[s] = 0;
	while(1)
	{
		minv = INF;
		u = -1;
		for(int i = 0; i < n; ++i)
		{
			if(!color[i] && d[i] < minv)
				minv = d[i], u = i;
		}
		if(u == -1)	break;
		color[u] = 1;
		for(int v = 0; v < n; ++v)
		{
			if(!color[v] && a[u][v]!=INF)
			{
				if(d[u]+a[u][v] < d[v])
				{
					d[v] = d[u]+a[u][v];
				}
			}
		}
	}
	for(int i = 0; i < n; ++i)
		cout<<i<<' '<< (d[i]==INF?-1:d[i])<<'\n';
}
int main(void)
{
	ios::sync_with_stdio(false); 
	//cin.tie(0);
	int u,v,k,w;
	memset(a,INF,sizeof a);
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>u>>k;
		for(int j = 1; j <= k; ++j)
		{
			cin>>v>>w;
			a[u][v] = w;
		}
	}
	dijkstra();
	return 0;
}
