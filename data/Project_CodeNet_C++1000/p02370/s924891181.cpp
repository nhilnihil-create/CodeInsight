#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define F first
#define S second 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> tpi;
typedef pair<pii,pii> qpi;
const int INF = 2e9;
const int MAX = 1e5;
const int MV = 1e5;
int MA = -INF , MI = INF;

int n , m;
vector<int> ans , adj[MAX+10];
int in[MAX+10];
bool vis[MAX+10];
queue<int> qu;

int32_t main()
{
	IO;
	cin >> n >> m;

	while(m--)
	{
		int u , v;
		cin >> u >> v;
		in[v]++;
		adj[u].push_back(v);
	}

	for(int i=0 ; i<n ; i++)
	{
		if( in[i] == 0 )
			qu.push(i) , vis[i] = 1;
	}

	while( ans.size() < n )
	{
		int v = qu.front();
		qu.pop();
		ans.push_back(v);
		
		for(int u : adj[v])
		{
			if( !vis[u] )
			{
				in[u]--;
				if( in[u] == 0 )
					qu.push(u) , vis[u] = 1;
			}
		}
	}
		
	for(int u : ans)
		cout << u << "\n";
	cout << "\n";
	return 0;
}