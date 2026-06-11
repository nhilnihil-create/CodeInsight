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

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const string code[] = { "root", "internal node", "leaf" };

struct Graph{
	int parent;
	int depth;
	int kind;	// 0: root 1: internal node 2: leaf
	vector<int> child;
};
Graph graph[100005];

void dfs (int prev, int curr )
{
	int record = graph[curr].parent;

	if (prev != -1 ){
		graph[curr].parent = prev;
	} // end if

	if (graph[curr].child.empty() ) return;

	if (prev != -1 && record == graph[curr].parent ) return;

	rep (i, graph[curr].child.size() ){
		dfs (curr, graph[curr].child[i] );
	} // end rep
}

void dfs2 (int curr, int depth )
{
	graph[curr].depth = depth;
//	visit[curr] = true;

	if (graph[curr].child.empty() ) return;

	rep (i, graph[curr].child.size() ){
//		if (!visit[graph[curr].child[i]] )
			dfs2 (graph[curr].child[i], depth+1 );
	} // end rep

}

int main()
{
//	cut here before submit 
//	freopen ("testcase.RT7", "r", stdin );
	int n;
	scanf ("%d", &n );
	vector<vector<int> > node (n );

	rep (i, n ){
		int m, k;
		scanf ("%d %d", &m, &k );
		rep (j, k ){
			int child;
			scanf ("%d", &child );
			node[m].push_back (child );
		} // end rep
	} // end rep

	rep (i, n ){
		graph[i].parent = -1;
		graph[i].depth  = -1;
		graph[i].kind   = -1;
		graph[i].child.clear();
	} // end rep

	rep (i, n ){
		rep (j, node[i].size() ){
			graph[i].child.push_back (node[i][j] );
		} // end rep
	} // end rep

	rep (i, n ){
		if (!graph[i].child.empty() ){
			dfs (-1, i );
		} // end if
	} // end rep

	rep (i, n ){
		if (!graph[i].child.empty() ){
			if (graph[i].parent == -1 ){
				graph[i].kind = 0;
			}else{
				graph[i].kind = 1;
			} // end if
		}else{
			if (graph[i].parent != -1 ){
				graph[i].kind = 2;
			}else{
				graph[i].kind = 0;
			} // end if
		} // end if
	} // end rep

//	memset (visit, false, sizeof (visit ) );
	rep (i, n ){
		if (graph[i].kind == 0 ){
			dfs2 (i, 0 );
			break;
		} // end if
	} // end rep

	rep (i, n ){
		cout << "node " << i << ": ";
		cout << "parent = " << graph[i].parent << ", ";
		cout << "depth = " << graph[i].depth << ", ";
		cout << code[graph[i].kind] << ", ";
		cout << '[';
		if (!graph[i].child.empty() ){
			int m = graph[i].child.size();
			rep (j, m ){
				cout << graph[i].child[j];
				if (j != m - 1 ){
					cout << ", ";
				} // end if
			} // end rep
		} // end if
		cout << ']' << endl;
	} // end rep

/*
	rep (i, n ){
		cout << "node[" << setw(2) << i << "]" << endl;
		cout << "parent: " << graph[i].parent << endl;
		cout << "depth:  " << graph[i].depth << endl;
		cout << "kind:   " << code[graph[i].kind] << endl;
		if (!graph[i].child.empty() ){
			rep (j, graph[i].child.size() ){
				cout << graph[i].child[j] << ' ';
			} // end rep
			cout << endl;
		} // end if
		cout << endl;
	} // end rep
*/
	return 0;
}