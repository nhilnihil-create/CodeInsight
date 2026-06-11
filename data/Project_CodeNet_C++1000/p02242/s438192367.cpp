#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()
#define INF 1<<20

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int cost[105][105];
int d[105];
bool used[105];

int dijkstra (int n )
{
	memset (used, false, sizeof (used ) );
	fill (d, d+n, INF );
	d[0] = 0;

	while (true ){
		int v = -1;
		// まだ使われていない頂点のうち距離が最小のものを探す
		rep (u, n )
			if (!used[u] && (v == -1 || d[u] < d[v] ) ) v = u;
		
		if (v == -1 ) break;
		
		used[v] = true;
		rep (u, n )
			d[u] = min (d[u], d[v] + cost[v][u] );
	} // end whle
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	rep (i, n ) rep (j, n ) cost[i][j] = INF;

	rep (i, n ){
		int u; cin >> u;
		int k; cin >> k;
		while (k-- ){
			int v, c; cin >> v >> c;
			cost[u][v] = c;
		} // end while
	} // end loop

	dijkstra (n );
	rep (i, n ) cout << i << ' ' << d[i] << endl;
		
	return 0;
}