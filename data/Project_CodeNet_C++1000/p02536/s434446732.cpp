#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

void visitPoint(int index, vector<vector<int>>& point, vector<bool>& visit) {
	if (visit[index]) {
		return;
	}

	visit[index] = true;
	for (int i = 0; i < point[index].size(); ++i) {
		int idx = point[index][i];
		visitPoint(idx, point, visit);
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> AB(N);
	vector<bool> visit(N);

	for (int i = 0; i < M; ++i) {
		int A, B;
		cin >> A >> B;
		if (find(AB[A - 1].begin(), AB[A - 1].end(), B-1) == AB[A - 1].end()) {
			AB[A - 1].push_back(B - 1);
		}
		if (find(AB[B - 1].begin(), AB[B - 1].end(), A - 1) == AB[B - 1].end()) {
			AB[B - 1].push_back(A - 1);
		}
	}
	
	visitPoint(0, AB, visit);

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (!visit[i]) {
			visitPoint(i, AB, visit);
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
