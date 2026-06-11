#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, m, i, j, a, b, s, t, d[100003][3] = {};
	vector<int> g[100003];

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
	}
	scanf("%d%d", &s, &t);

	s--;
	t--;

	for (i = 0; i < n; i++) for (j = 0; j < 3; j++) {
		d[i][j] = INF;
	}

	P p;
	int ds, pv, pr, nv, nr;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(0, s * 3));
	d[s][0] = 0;
	while (!pq.empty()) {
		p = pq.top();
		pq.pop();
		ds = p.first;
		pv = p.second / 3;
		pr = p.second % 3;
		if (d[pv][pr] < ds) {
			continue;
		}
		for (i = 0; i < g[pv].size(); i++) {
			nv = g[pv][i];
			nr = (pr + 1) % 3;
			if (d[nv][nr] > ds + 1) {
				d[nv][nr] = ds + 1;
				pq.push(P(ds + 1, nv * 3 + nr));
			}
		}
	}

	if (d[t][0] == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", d[t][0] / 3);
	}

	return 0;
}