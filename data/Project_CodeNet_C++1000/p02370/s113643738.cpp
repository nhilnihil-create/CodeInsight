#pragma GCC optimize("Ofast")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

struct edge {
	ll to;
	ll cost;
};

void toposo_(vector<vector<edge>>& g, vector<int>& used, vector<int>& l, int pos) {
	if (!used[pos]) {
		used[pos] = 1;
		for (int i = 0; i < g[pos].size(); i++) {
			toposo_(g, used, l, g[pos][i].to);
		}
		l.push_back(pos);
	}
}
vector<int> toposo(vector<vector<edge>>& g) {
	vector<int> u(g.size(),0), ret;
	for (int i = 0; i < g.size(); i++)toposo_(g, u, ret, i);
	reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<edge>> g(V);
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back({ b,1 });
	}
	auto c = toposo(g);

	for (int i = 0; i < c.size(); i++)cout << c[i] << endl;
}
