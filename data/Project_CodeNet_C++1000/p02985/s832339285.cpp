#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{ return firstElof.second < secondElof.second; }
//**Snippetリスト**//
//rep, vin, all//
//gcdlcm, isPrime, eratos, modinv, bitSearch, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l, m, n; ll N, M, K, H, W, L; 
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 1;
vl flag, color; vll path; vl D; ll S, T;
//***********//
void bfs(ll now) {
	queue<ll> Q;
	Q.push(now);
	D[now] = 0;
	flag[now] = 1;
	ll u;
	ans = K;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		ll color;
		if (D[u] == 0)color = K - 1;
		else color = K - 2;
		for (ll v = 0; v < path[u].size(); v++) {
			ll next = path[u][v];
			if (flag[next] == 0) {
				D[next] = D[u] + 1;
				flag[next] = 1;
				Q.push(next);
				ans = (ans * color) % MOD;
				color--;
			}
		}
	}
}
int main() {
	cin >> N >> K;
	path.resize(N);
	flag.resize(N);
	D.resize(N);
	for (i = 0; i < N; i++) {
		flag[i] = 0;
	}
	for (i = 0; i < N-1; i++) {
		ll a, b;
		cin >> a >> b;
		path[a - 1].push_back(b - 1);
		path[b - 1].push_back(a - 1);
	}
	bfs(0);
	cout << ans;
}
