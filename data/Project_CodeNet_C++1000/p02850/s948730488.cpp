#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

void BFS(vector<vector<pair<int, int>>> &G, int &max) {
	queue<pair<int, int>> que;
	que.push(make_pair(1, -1)); // チェックするノード番号, 直前の色

	while (!que.empty()) {
		int num = que.front().first;
		int color = que.front().second;
		que.pop();
		int edge = G[num - 1].size();
		if (color != -1)edge++;
		if (edge > max)max = edge;

		rep(i, G[num - 1].size()) {
			if (G[num - 1][i].second == color)G[num - 1][i].second = G[num - 1].size() + 1;
			que.push(make_pair(G[num - 1][i].first, G[num-1][i].second));
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> G(N);
	vector<pair<int, int>> input(N - 1);

	int a, b;
	rep(i, N-1) {
		cin >> a >> b;
		G[a - 1].push_back(make_pair(b, G[a - 1].size() + 1));
		input[i] = make_pair(a, b);
	}

	//cout << "aaa" << endl;
	int K = 0;
	BFS(G, K);
	cout << K<< endl;
	rep(i, N - 1) {
		rep(j, G[input[i].first - 1].size()) {
			if (input[i].second == G[input[i].first - 1][j].first) {
				cout << G[input[i].first - 1][j].second << endl;
				break;
			}
		}
	}



}