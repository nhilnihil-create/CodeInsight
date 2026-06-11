#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using LL = long long;

int main() {
	int N, X, Y;
	cin >> N >> X >> Y;
	vector<int> ans(N+1, 0);
	vector<vector<int>> dist(N + 1, vector<int>(N+1, -1));

	for (int i = 1; i <= N - 1; i++) {
		queue<int> que;
		que.push(i);
		dist[i][i] = 0;
		while (!que.empty()) {
			int p = que.front();
			que.pop();
			if (p > 1 && dist[i][p - 1] == -1) {
				que.push(p - 1);
				dist[i][p - 1] = dist[i][p] + 1;
			}
			if(p+1 <= N && dist[i][p + 1] == -1){
				que.push(p + 1);
				dist[i][p + 1] = dist[i][p] + 1;
			}
			if (p == X && dist[i][Y] == -1) {
				que.push(Y);
				dist[i][Y] = dist[i][p] + 1;
			}


		}

		LL tem = 0;

	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			ans[dist[i][j]]++;
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		cout << ans[i] << endl;
	}
	dist[0][0];
	return 0;

}