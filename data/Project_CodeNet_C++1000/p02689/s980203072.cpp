#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> H(N);
	vector<vector<int>> G(N);
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		bool ok = true;
		for (int j : G[i]) {
			if (H[i] <= H[j]) ok = false;
		}
		if (ok) count++;
	}

	cout << count << endl;

	return 0;
}