#include "bits/stdc++.h"
using namespace std;
vector<int>to[100005];
const int INF = 1001001001;
int dist[100005][3];

int main() {
	int N, M;
	cin >> N >> M;
	for (int n = 0; n < M; ++n) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		to[a].push_back(b);
	}
	int sv, tv;
	cin >> sv >> tv;
	--sv;
	--tv;
	for (int i = 0;i<N;++i) {
		for (int j = 0;j<3;++j) {
			dist[i][j] = INF;
		}
	}
	dist[sv][0] = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(sv,0));
	while (!q.empty()) {
		int v = q.front().first;
		int l = q.front().second;
		q.pop();
		for (int e : to[v]) {
			int nl = (1+l) % 3;
			if (INF != dist[e][nl]) {
				continue;
			}
			dist[e][nl] = dist[v][l] + 1;
			q.push(make_pair(e, nl));
		}
	}
	int ans = dist[tv][0];
	if (INF == ans) {
		cout << -1 <<endl;
	}
	else {
		cout << ans/3<<endl;
	}
	return 0;
}