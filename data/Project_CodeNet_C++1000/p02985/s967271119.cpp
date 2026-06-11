/*dismint|jjc*/
#include <bits/stdc++.h>
using namespace std;
#define forl(V, S, E) for(int V = S; V < E; V++)
#define ford(V, S, E) for(int V = S; V >= E; V--)
#define fore(E, X) for(auto &E:X)
#define println(X) cout << X << endl
#define printe(X) for(auto &E:X) cout << E << " "; cout << endl
typedef unordered_map<int, unordered_set<int>> graph;
typedef long long ll;

const ll mod = 1e9+7;
ll factorial[200000];
graph G;

map<int, int> parent, subtree;
void est(int root) {
	stack<pair<int, int>> S; S.push(make_pair(root, 0));
	unordered_set<int> VST;
	while(!S.empty()) {
		pair<int, int> VP = S.top(); S.pop(); int V = VP.first;
		if(VST.count(V) > 0) {
			subtree[parent[V]] += ++subtree[V];
			continue;
		}
		VST.insert(V); S.push(VP);
		fore(NB, G[V]) {
			if(VST.count(NB) > 0) continue;
			parent[NB] = V;
			S.push(make_pair(NB, V));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, k; cin >> n >> k;
	forl(i, 0, n-1) { int a, b; cin >> a >> b; G[a].insert(b); G[b].insert(a); }
	est(1); factorial[0] = 1; forl(i, 1, 200000) factorial[i] = (factorial[i-1]*i)%mod;
	ll ans = k;
	forl(i, 1, n+1) {
		ll op = k, nm = (int)G[i].size()-1;
		if(i == 1) { op--; nm++; }
		else op -= 2;
		while(nm--) {
			ans = (ans*(op--))%mod;
		}
	}
	println(ans);
}
