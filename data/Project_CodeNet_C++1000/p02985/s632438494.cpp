#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = (int)1e9 + 7, INF = (int)1e9;


int d[100003] = {};
ll lb[100003] = {}, m[100003];
vector<int> g[100003];

void dfs(int p) {
	int i, x;

	x = 0;
	m[p] = 1;
	for (i = 0; i < g[p].size(); i++) {
		if (d[g[p][i]] > d[p]) {
			dfs(g[p][i]);
			m[p] = m[p] * m[g[p][i]] % mod;
			x++;
		}
	}

	if (p == 0) {
		m[p] = m[p] * lb[x - 1] % mod;
	}
	else {
		m[p] = m[p] * lb[x] % mod;
	}

}

int main(void) {
	int n, k, i, a, b, p;
	ll ans;
	queue<int> q;

	scanf("%d%d", &n, &k);

	if (n == 1) {
		printf("%d\n", k);
		return 0;
	}

	for (i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	q.push(0);
	d[0] = 1;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (i = 0; i < g[p].size(); i++) {
			if (d[g[p][i]] == 0) {
				d[g[p][i]] = d[p] + 1;
				q.push(g[p][i]);
			}
		}
	}

	lb[0] = 1;
	lb[1] = k - 2;
	for (i = 2; i <= k - 1; i++) {
		lb[i] = lb[i - 1] * (k - i - 1) % mod;
	}

	dfs(0);

	ans = m[0] * (k - 1) % mod * k % mod;

	printf("%lld\n", ans);

	return 0;
}