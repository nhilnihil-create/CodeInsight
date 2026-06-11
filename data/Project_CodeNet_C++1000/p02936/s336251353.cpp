#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <cmath>
//#include <iomanip>
//#include <map>
//#include <unordered_map>
//#include <cstring>

using namespace std;
using ll = long long;
// using pint = pair<int, int>;
using Graph = vector<vector<int>>;
// ll INF = 1LL << 60;

vector<ll> counter;
Graph G;

void dfs(int v, int pv) {
	if (pv != -1) counter[v] += counter[pv];
	for (int nv : G[v]) {
		if (nv == pv) continue;
		dfs(nv, v);
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	G.resize(N);
	counter.resize(N);
	counter.assign(N, 0);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> p(Q), x(Q);
	for (int i = 0; i < Q; i++) {
		int p, x;
		cin >> p >> x;
		p--;
		counter[p] += x;
	}

	dfs(0, -1);

	for (int i = 0; i < N; i++) cout << counter[i] << " ";

	return 0;
}