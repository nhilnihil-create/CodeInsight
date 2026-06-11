#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define oset tree < int ,  null_type ,  less ,  rb_tree_tag ,  tree_order_statistics_node_update >
#define endl '\n'
#define int long long int
#define db long double
#define str string
#define mod 1000000007
#define ff first
#define ss second
#define pqi priority_queue<int>
#define vi vector<int>
#define si set<int>
#define li list<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define For(i,s,n) for(int i=s;i<n;i++)
#define read(a) {for(auto &x:a)cin >> x;}
#define print(x) cout<<x<<endl
#define mat2D(T,r,c) vector<vector<int> > T(r,vector<int>(c))
#define vec2D vector<vector<int> >
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) {for(auto i :x) cout << i << " ";cout << endl;}
#define debPair(x) {for(auto i :x) cout << i.ff << " " << i.ss << endl;}

map<int, vector<int>> adj;
// map<int, bool> visited;
bool ok = false;

void addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int src, bool visited[]) {
	// cout << src << ' ';
	ok = true;
	visited[src] = true;
	for (auto nbr : adj[src]) {
		if (!visited[nbr]) dfs(nbr, visited);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	set<int> s;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		addEdge(a, b);
	}
	bool visited[n + 1] = {false};
	int c = 0 ;
	// for (int i = 1; i <= n; i++) visited[i] = false;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) dfs(i, visited);
		if (ok) ++c;
		ok = false;
		// cout << endl;
	}
	cout << c - 1;
}

int32_t main() {
	fastIO;
	/*
	int t;
	cin >> t;
	For(i, 1, t + 1) {
	  // cout << "Case " << i << ": ";
	  solve();
	}*/
	solve();
	return 0;
}