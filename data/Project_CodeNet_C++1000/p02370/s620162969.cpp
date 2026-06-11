#include <bits/stdc++.h>
using namespace std;

#define INF INT32_MAX

int main()
{
	int V, E;
	cin >> V >> E;
	vector<vector<int>> g( V );
	vector<int> indeg( V );
	vector<int> color( V );
	for( int i = 0; i < E; i++ ) {
		int s, t;
		cin >> s >> t;
		g[s].push_back( t );
		indeg[t]++;
	}

	vector<int> out;
	for( int i = 0; i < V; i++ ) {
		if( color[i] || indeg[i] ) continue;
		queue<int> que;
		que.push( i );
		color[i] = 1;
		while( !que.empty() ) {
			int u = que.front();
			que.pop();
			out.push_back( u );
			for( int v : g[u] ) {
				indeg[v]--;
				if( indeg[v] || color[v] ) continue;
				color[v] = 1;
				que.push( v );
			}
		}
	}

	for( int i = 0; i < out.size(); i++ ) {
		cout << out[i] << endl;
	}
}

