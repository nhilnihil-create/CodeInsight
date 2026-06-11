#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	vector<vector<int>> Match(N, vector<int>(N, -1));
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int ii = i, jj = j;
			if (Match[i][j] >= 0) continue;
			while (S[ii] == S[jj] && jj<N) {
				ii++;
				jj++;
			}
			int MAX = ii - i;
			Match[i][j] = min(MAX, j-i);
			ii = i, jj = j;
			while (MAX > 0 && ii + 1 < N && jj + 1 < N) {
				Match[ii + 1][jj + 1] = min(MAX - 1, jj - ii);
				MAX--;
				ii++;
				jj++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) ans = max(ans, Match[i][j]);
	cout << ans << endl;
}
