#include <bits/stdc++.h>
using namespace std;

#define MAX 200000
#define WHITE 0
#define BLACK 1
int N, Q;
vector<int> T[MAX + 1];
int X[MAX + 1];
int ans[MAX + 1];
int col[MAX + 1];

int main() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		X[i] = 0;
		col[i] = WHITE;
	}
	for (int i = 1; i <= N - 1; i++) {
		int a, b;
		cin >> a >> b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	for (int j = 1; j <= Q; j++) {
		int p, x;
		cin >> p >> x;
		X[p] += x;
	}
	queue<pair<int, int>> Q;
	Q.push(make_pair(1, 0));
	col[1] = BLACK;
	while (!Q.empty()) {
		auto u = Q.front();
		Q.pop();
		ans[u.first] = u.second + X[u.first];
		for (auto v : T[u.first]) {
			if (col[v] == WHITE) {
				Q.push(make_pair(v, ans[u.first]));
				col[v] = BLACK;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}