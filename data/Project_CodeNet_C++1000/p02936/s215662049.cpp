#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vll = vector<vl>;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define RES(a, n) (a).resize(n)
ll n, q;
vl a, b, p, x;
vl cost;
vll G;
vector<bool> seen;
void dfs(ll v){
	seen[v] = true;
	for(auto nv : G[v]){
		if(seen[nv]) continue;
		cost[nv] += cost[v];
		dfs(nv);
	}
}
int main() {
	cin >> n >> q;
	RES(a, n-1);
	RES(seen, n);
	RES(G, n);
	RES(b, n-1);
	RES(cost, n);
	RES(p, q);
	RES(x, q);
	REP(i, n-1){
		cin >> a[i] >> b[i];
		G[a[i]-1].push_back(b[i]-1);
		G[b[i]-1].push_back(a[i]-1);
	}
	REP(i, q){
		cin >> p[i] >> x[i];
		cost[p[i]-1] += x[i];
	}
	dfs(0);
	REP(i, n){
		cout << cost[i] << " ";
	}
	cout << endl;
	return 0;
}