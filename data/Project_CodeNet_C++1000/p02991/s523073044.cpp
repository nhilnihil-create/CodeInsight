#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;


const int INF = 1000000000;
const ll BIG_NUM = 1000000000000000000;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(3 * n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		g[u].emplace_back(v + n);
		g[u + n].emplace_back(v + 2 * n);
		g[u + 2 * n].emplace_back(v);
	}

	int s, t;
	cin >> s >> t;
	s--;
	t--;



	vector<ll> d(3 * n, INF);
	vector<bool> isChecked(3 * n, false);
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		for (auto it = g[v].begin(); it != g[v].end(); it++) {
			if (!isChecked[*it] && d[*it] > d[v] + 1) {
				d[*it] = d[v] + 1;
				pq.push(make_pair(d[*it], *it));
			}
		}

		isChecked[v] = true;
	}

	ll dt = INF;
	for (int i = 0; i < 3; i++) {
		if (d[t + i * n] % 3 == 0) {
			dt = min(dt, d[t + i * n] / 3);
		}
	}

	if (dt == INF) {
		dt = -1;
	}
	cout << dt << endl;
}


