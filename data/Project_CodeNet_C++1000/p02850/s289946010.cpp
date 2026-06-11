#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

void BFS(vector<vector<pair<int, int>>> &G, int &max, vector<int> &ans) {
	queue<pair<int, int>> que;
	que.push(make_pair(1, -1)); // チェックするノード番号, 直前の色
	map<int, int> check;
	check[1]++;

	while (!que.empty()) {
		int num = que.front().first;
		int color = que.front().second;
		que.pop();
		int edge = G[num - 1].size();
		if (edge > max)max = edge;

		int count = 1;
		rep(i, G[num - 1].size()) {
			if (check[G[num - 1][i].first] == 0) {
				if (count == color)count++;
				ans[G[num - 1][i].second] = count;
				que.push(make_pair(G[num - 1][i].first, count));
				check[G[num - 1][i].first]++;
				count++;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> G(N);
	vector<int> ans(N - 1);

	int a, b;
	rep(i, N-1) {
		cin >> a >> b;
		G[a - 1].push_back(make_pair(b, i));
		G[b - 1].push_back(make_pair(a, i));
	}

	int K = 0;
	BFS(G, K, ans);
	cout << K<< endl;
	rep(i, N - 1) {
		cout << ans[i] << endl;
	}
}