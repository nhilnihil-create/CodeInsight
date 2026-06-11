#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <deque>
#include <queue>
#include <map>
#include <iterator>
#include <set>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e) { std::cout << e << std::endl; }
template<typename T> void view(const std::vector<T>& v) { for (const auto& e : v) { std::cout << e << " "; } std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v : vv) { view(v); } }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int mxN = 2e5 + 6;
vector<int> G[mxN];
int dist[mxN][3];
const int INF = 1e9;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
	}

	int s, t;
	cin >> s >> t;
	s--, t--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dist[i][j] = INF;
		}
	}
	dist[s][0] = 0;

	queue<P> Q;
	Q.push(P(s, 0));

	while (!Q.empty()) {
		P p = Q.front();
		Q.pop();
		int nv = p.first;
		int mod = p.second;
		int nextm = (mod + 1) % 3;
		for (auto e : G[nv]) {
			if (dist[e][nextm] == INF) {
				dist[e][nextm] = dist[nv][mod] + 1;
				Q.push(P(e, nextm));
			}
		}
	}

	int ans;
	if (dist[t][0] != INF) {
		ans = dist[t][0] / 3;
	}
	else {
		ans = -1;
	}
	cout << ans << endl;

}