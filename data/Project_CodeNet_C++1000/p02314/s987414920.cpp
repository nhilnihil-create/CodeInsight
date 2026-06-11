#include <bits/stdc++.h>

using namespace std;

int dist[111111];
int a[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<=n;i++) dist[i]=int(1e9);
	dist[n]=0;
	for(int i=0;i<m;i++) cin>>a[i];
	queue<int> q; q.push(n);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<m;i++)
		{
			if(u-a[i]>=0&&dist[u-a[i]]>=int(1e9))
			{
				dist[u-a[i]]=dist[u]+1; q.push(u-a[i]);
			}
		}
	}
	cout<<dist[0]<<'\n';
}