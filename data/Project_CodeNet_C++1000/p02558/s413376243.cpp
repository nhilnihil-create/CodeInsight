#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define umap unordered_map
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 
#define printVerdict(verdict) cout << (verdict ? "YES": "NO") << '\n'
#define printDecimal(d) printf("%.9f\n", d)
#define inrange(val, start, end) (val >= start && val <= end)
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
const ll mod = 1e9 + 7; 
const int inf = 0x3f3f3f3f;
 
template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) { cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n'; }
template <class T1, class T2>
void printPair(pair<T1, T2> p) { cout << p.first << " " << p.second  << '\n'; }
template <class T>
void printArray(vector<T> arr) { for (int i = 0; i<size(arr); i++) {cout << arr[i] << " ";} cout << '\n'; } 
 
int find_rep(int u, vector<int> &parent) {
	if (parent[u] != u) parent[u] = find_rep(parent[u], parent);
	return parent[u];
}

void merge(int u, int v, vector<int> &parent, vector<int> &sz) {
	u = find_rep(u, parent), v = find_rep(v, parent);
	if (u != v) {
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		parent[v] = u;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q; cin >> n >> q;
	vector<int> parent(n), sz(n, 1);
	for (int i = 0; i<n; i++) parent[i] = i, sz[i] = 1;
	while (q--) {
		int t,u,v; cin >> t >> u >> v;
		if (t == 0) merge(u, v, parent, sz);
		else cout << (find_rep(u, parent) == find_rep(v, parent)) << '\n';
	}
} 
