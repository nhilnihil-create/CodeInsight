#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1 << 30;

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> C(N);
	vector<int> understand(M);
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		cin >> C[i];
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int price = INF;

	for (int bit = 0; bit < (1 << N); bit++) {
		understand.assign(M, 0);
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (bit & (1 << i)) {
				sum += C[i];
				for (int j = 0; j < M; j++) {
					understand[j] += A[i][j];
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < M; i++) {
			if (understand[i] < X) ok = false;
		}
		if (ok) price = min(price, sum);
	}

	if (price == INF) cout << -1 << endl;
	else cout << price << endl;

	return 0;
}
