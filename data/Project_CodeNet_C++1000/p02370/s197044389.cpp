#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
#define MAX_V (10010)

vector<int> G[MAX_V];
int indeg[MAX_V];
bool arrived[MAX_V];
vector<int> ans;

void bfs( int s ) {
    queue<int> Q;
    Q.push( s );
    
    while ( !Q.empty() ) {
	int v = Q.front(); Q.pop();
	ans.push_back( v );
	for ( int i = 0; i < G[v].size(); i++ ) {
	    int t = G[v][i];
	    indeg[t]--;
	    if ( indeg[t] == 0 && !arrived[t] ) {
		arrived[t] = true;
		Q.push( t );
	    }
	}
    }
}


int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    
    for ( int i = 0; i < E; i++ ) {
	int s, t;
	scanf("%d %d", &s, &t);
	G[s].push_back( t );
        indeg[t]++;
    }

    for ( int i = 0; i < V; i++ ) {
	if ( !arrived[i] && indeg[i] == 0 ) {
	    arrived[i] = true;
	    bfs( i );
	}
    }

    for ( int i = 0; i < ans.size(); i++ ) {
	printf("%d\n", ans[i] );
    }


    return 0;
}