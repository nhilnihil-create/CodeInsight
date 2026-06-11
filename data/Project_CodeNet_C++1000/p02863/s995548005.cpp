#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	vector<vector<int>> DP(N, vector<int>(T + 1, 0));
	vector<pair<int,int>> AB(N);
	for (int i = 0; i < N; i++) cin >> AB[i].first >> AB[i].second;
	sort(AB.begin(), AB.end());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= T; j++) {
			if (i == 0) {
				if (j <= T - AB[i].first) DP[i][j] = AB[i].second;
			}
			else {
				if (j + AB[i].first <= T) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j + AB[i].first] + AB[i].second);
				else DP[i][j] = DP[i - 1][j];
				if (j == 0) DP[i][j] = max(DP[i - 1][0], DP[i - 1][1] + AB[i].second);
			}
		}
	}
	cout << DP[N - 1][0] << endl;
}
