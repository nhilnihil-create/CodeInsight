#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


struct edge {
	ll to;
	ll cost;
};
typedef pair<ll, ll> P;

void dijkstra(int s, vector<vector<edge>>& g, vector<ll>& d) {
	priority_queue<P, vector<P>, greater<P>> q;
	d = vector<ll>(g.size(), INF_LL);
	d[s] = 0;
	q.push(P{ 0,s });

	while (!q.empty()) {
		P p = q.top(); q.pop();
		ll v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < g[v].size(); i++) {
			edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				q.push(P{ d[e.to] , e.to });
			}
		}
	}
}


int main() {
	int N, M, S, T;
	cin >> N >> M;
	vector<vector<edge>> g(N * 3);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back({ N + v,1 });
		g[N + u].push_back({ N * 2 + v,1 });
		g[N * 2 + u].push_back({ v,1 });
	}
	cin >> S >> T;
	vector<ll> d;
	dijkstra(S - 1, g, d);
	if (d[T - 1] == INF_LL) {
		cout << -1 << endl;
		return 0;
	}
	cout << d[T - 1]/3 << endl;
}