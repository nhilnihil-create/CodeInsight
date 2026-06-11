/*input
10
5 3
5 7
8 9
1 9
9 10
8 4
7 4
6 10
7 2
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define tests int t; cin >> t; while(t--)
#define MP make_pair
#define PI acos(-1)
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define godspeed ios_base::sync_with_stdio(false); cin.tie(NULL);

#define MOD(x) ((x)%(1000000007))

int main() {
	godspeed;
	int n;
	cin >> n;
	int64 u, v;
	int64 numComp = 0;
	for(int64 i = 1; i < n; i++) {
		numComp += i*(n-i+1); 
		cin >> u >> v;
		numComp -= min(u, v)*(n-max(u, v)+1); 
	}
	numComp += n;
	cout << numComp << endl;
}


/*
Let S be the set of the vertices numbered L through R. 
f(L,R) represents the number of connected components in 
the subgraph formed only from the vertex set S and the edges
whose endpoints both belong to S.

None of these connected components can have a cycle because 
G is a tree. Therefore all connected components are trees.
In a tree num V = num E + 1 so adding all connected comps
num V in all connected comps = num E in all connected comps + 
num connected comps

Therefore f(L, R) = (R-L+1) + num E whose u_i \in [L, R] and 
v_i \in [L, R]

Subtract this:
Each edge (L, R) is included L*(N-R+1) times where L<=R. 

Add this:
Each Vertex x is included X*(N-X+1) times.
*/