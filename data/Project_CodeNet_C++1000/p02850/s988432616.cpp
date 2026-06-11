#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int edge_color[100005];
int max_color;

struct edge {
	int edge_id;
	int next_node;
};

vector<edge> e[100005];

void dfs( int node, int parent_node, int used_color ){
	int color = 0;
	for ( auto it : e[node] ){
		if ( it.next_node == parent_node )
			continue;
		if ( color == used_color )
			color++;
		edge_color[it.edge_id] = color;
		dfs( it.next_node, node, color );
		color++;
	}
	max_color = max( max_color, color );
}


int main(){
	cin >> N;
	
	for ( int i = 0; i < N-1; i++ ){
		int aa, bb;
		cin >> aa >> bb;
		aa--;
		bb--;
		
		e[aa].push_back({i,bb});
		e[bb].push_back({i,aa});
	}
	
	dfs( 0, -1, -1 );
	
	cout << max_color << endl;
	for ( int i = 0; i < N-1; i++ ){
		cout << (edge_color[i]+1) << endl;
	}
	
	return 0;
}

