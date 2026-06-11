/*
	Created on 29-09-20 13:17

	@author: roastedcoder
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MAX = 1e6 + 5;
const int N = 1e5 + 5;
//const int MAXX = 1e14;

//#define ll long long
#define int long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pb push_back
#define roastedcoder ios_base::sync_with_stdio(false); cin.tie(NULL);
//__________________________________________________________________

vector <int> graph[MAX];
bool vis[MAX];

void dfs(int node) {
	vis[node] = true;
	for(auto child : graph[node])
		if(!vis[child])
			dfs(child);
}

int32_t main() {
	roastedcoder
	int n, m; cin>>n>>m;
	while(m--) {
		int a, b; cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	int res = 0;
	for(int i = 1; i<=n; i++) {
		if(!vis[i]) {
			dfs(i);
			res += 1;
		}
	}
	// res = number of connected component so number of roads will be res-1
	cout<<res-1<<endl;
}

//__________________________________________________________________
/*
Sample Input:


Sample Output:


*/
/*
MY NOTES:
  int for long long
  Don't make Segment Tree and Fenwick Tree 0-based you FOOL.
  Always try to exhaust the time being provided and PACE yourself.
*/