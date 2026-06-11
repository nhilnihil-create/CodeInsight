#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, M, X;
	cin >> N >> M >> X;

	vector<int> C(N);
	vector<vector<int>> A(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		cin >> C[i];
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}

	int ans = 100000000;
	for (int i = 1; i < (1 << (N+1)); ++i) {
		int money = 0;
		vector<int> total(M, 0);
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				for (int k = 0; k < M; ++k) {
					total[k] += A[j][k];
				}
				money += C[j];
			}
		}

		bool ok = true;
		for (int k = 0; k < M; ++k) {
			if (total[k] < X) {
				ok = false;
				break;
			}
		}

		if (ok) {
			ans = min(ans, money);
		}
	}
	cout << (ans == 100000000 ? -1 : ans)<< endl;

	return 0;
}
