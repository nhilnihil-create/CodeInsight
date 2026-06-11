#include <bits/stdc++.h>
using namespace std;

int indeg[10005];
int ts[10005], tt = 0;
int q[10005], qh = 0, qt = 0;
vector<int> G[10005];

int main() {
	int v, e; cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		indeg[b]++;
	}
	for (int i = 0; i < v; i++)
		if (!indeg[i])
			q[qt++] = i;
	while (qh < qt) {
		int t = q[qh++];
		ts[tt++] = t;
		for (int h : G[t]) {
			indeg[h]--;
			if (!indeg[h]) q[qt++] = h;
		}
	}
	for (int i = 0; i < tt; i++) cout << ts[i] << endl;
}
