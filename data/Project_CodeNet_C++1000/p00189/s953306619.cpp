#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main() {
	int N, M;
	while ( cin >> M, M ) {
		int cost[100][100]; fill(cost[0], cost[100], INF);
		set<int> s;
		for (int i = 0; i < M; ++i) {
			int a, b, c; cin >> a >> b >> c;
			cost[a][b] = cost[b][a] = c;
			s.insert(a);
			s.insert(b);
		}
		vector<int> v;
		for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
			v.push_back(*it);
		}
		N = (int)v.size();
		for (int i = 0; i < N; ++i) cost[i][i] = 0;
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					cost[v[i]][v[j]] = min(cost[v[i]][v[j]], cost[v[i]][v[k]]+cost[v[k]][v[j]]);
				}
			}
		}
		int aid = -1, asum = 0;
		for (int i = 0; i < N; ++i) {
			int sum = 0;
			for (int j = 0; j < N; ++j) {
				sum += cost[v[i]][v[j]];
			}
			if (aid < 0 || sum < asum) {
				aid = i;
				asum = sum;
			}
		}
		cout << aid << " " << asum << endl;
	}
}