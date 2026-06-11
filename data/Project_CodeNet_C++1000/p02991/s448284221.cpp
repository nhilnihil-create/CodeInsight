#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	vvi e(3*n);
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--;v--;
		rep(j, 3)e[j * n + u].push_back(((j + 1) % 3) * n + v);
	}
	int s, t;
	cin >> s >> t;
	s--;t--;

	vi dist(3 * n, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();q.pop();
		for (auto vv : e[v]) {
			if (dist[vv] < INF)continue;
			dist[vv] = dist[v] + 1;
			q.push(vv);
		}
	}

	if (dist[t] == INF)dist[t] = -3;
	cout << dist[t] / 3 << endl;
}