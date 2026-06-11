#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vi g[maxn];
int s, t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
	}
	queue<pair<int, int>> q;
	vector<vi> dist(n+1, vi(3, 1<<30));
	cin >> s >> t;
	q.push({s, 0});
	dist[s][0] = 0;
	int u, r;
	while(!q.empty()) {
		tie(u, r) = q.front();
		q.pop();
		int nr = (r+1)%3;
		for(auto i : g[u]) {
			if(dist[i][nr]==1<<30) {
				dist[i][nr] = dist[u][r] + 1;
				q.push({i, nr});
			}
		}
	}
	if(dist[t][0]==1<<30) dist[t][0] = -3;
	cout << dist[t][0]/3;
}
