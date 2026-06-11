#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int num = 10000;
vector<int> ne[num];
int pre[num], c[num], n;
queue<int> ans, q;
inline void bfs(int a) {
	q.push(a);
	c[a] = 1;
	while (!q.empty()) {
		int x = q.front();
		ans.push(x);
		q.pop();
		for (int j = 0; j < ne[x].size(); j++) {
			int k = ne[x][j];
			pre[k]--;
			if (pre[k] == 0) {
				q.push(k); c[k] = 1;
			}
		}
	}
}
inline void tp() {
	for (int i = 0; i < n; i++)
		if (c[i] == 0 && pre[i] == 0) bfs(i);
}
int main() {
	int p, s, t;
	cin >> n >> p;
	for (int i = 0; i < n; i++) pre[i] = 0;
	for (int i = 0; i < p; i++) {
		scanf("%d%d", &s, &t);
		ne[s].push_back(t);
	}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < ne[i].size(); j++) pre[ne[i][j]]++;
	for (int i = 0; i < n; i++) c[i] = 0;
	tp();
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans.front());
		ans.pop();
	}
	return 0;
}