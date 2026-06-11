#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> Keys(M);
	for (int i = 0; i < M; i++) {
		int b;
		cin >> Keys[i].first >> b;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			Keys[i].second += (1 << (c - 1));
		}
	}
	vector<vector<int>> DP(M+1, vector<int>(1 << N, 1<<29));
	for (int i = 0; i < M + 1; i++) DP[i][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) {
			int next = j | Keys[i - 1].second;
			int before = DP[i - 1][next];
			int now = DP[i - 1][j] + Keys[i - 1].first;
			DP[i][next] = min({ before, now, DP[i][next] });
			DP[i][j] = min(DP[i][j], DP[i - 1][j]);
		}
	}
	cout << (DP[M][(1 << N) - 1] < (1 << 29) ? DP[M][(1 << N) - 1] : -1) << endl;
}