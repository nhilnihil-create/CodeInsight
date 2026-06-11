#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	int h[n];
	for(int i = 0; i<n; i++) cin >> h[i];
	vector<int> adj[n];
	
	for(int i =0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	int bad[n] = {};
	for(int i = 0; i<n; i++)
	{
		if(bad[i]) continue;
		int height = h[i];
		for(int x :adj[i])
		{
			if(h[x] >= height)
			{
				bad[i] = 1;
				break;
			}
			else bad[x] = 1;
		}
	}
	for(int x :bad)
	{ 
		if(x == 0) cnt++;
	}	
	cout << cnt << "\n";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
