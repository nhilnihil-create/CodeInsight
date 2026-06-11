#include <cstdio>
#include <vector>

using namespace std;

#define MAX_V (10010)
vector<int> G[MAX_V];
int I[MAX_V];			// ??\?¬???°
bool arrived[MAX_V];
vector<int> ans;
void dfs( int s ) {
    ans.push_back( s );
    arrived[s] = true;
    for ( int i = 0; i < G[s].size(); i++ ) {
	int t = G[s][i];
	I[t]--;
	if ( I[t] == 0 ) {
	    dfs( t );
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
        I[t]++;
    }

    for ( int i = 0; i < V; i++ ) {
	if ( !arrived[i] && I[i] == 0 ) dfs( i );
    }

    for ( int i = 0; i < ans.size(); i++ ) {
	printf("%d\n", ans[i] );
    }
    
    return 0;
}