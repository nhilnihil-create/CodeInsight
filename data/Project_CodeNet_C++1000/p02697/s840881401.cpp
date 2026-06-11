#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> ans;
	if (N % 2) {
		for (int i = 1; i <= N / 2; ++i) {
			ans.emplace_back(i, N - i);
		}
	} else {
		int n = N / 2 - 1;
		for (int i = 1; i <= n; ++i) {
			if (i <= (n + 1) / 2) {
				ans.emplace_back(i, N - i + 1);
			} else {
				ans.emplace_back(i, N - i);
			}
		}
	}

	for (int i = 0; i < min(M, (int)ans.size()); ++i) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}
