#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> g(N * N);
	vector<int> d(N * N, 0);
	for (int i = 0; i < N; ++i) {
		vector<int> A(N - 1);
		for (auto& x : A) {
			cin >> x;
			--x;
		}
		for (int j = 0; j + 1 < N - 1; ++j) {
			int x1 = min(i, A[j]);
			int y1 = max(i, A[j]);
			int x2 = min(i, A[j + 1]);
			int y2 = max(i, A[j + 1]);

			int src = x1 * N + y1;
			int dst = x2 * N + y2;

			g[src].push_back(dst);
			++d[dst];
		}
	}

	queue<int> q;
	for (int i = 0; i < N * N; ++i) {
		int x = i / N;
		int y = i % N;
		//cout << "d[" << x << "][" << y << "]=" << d[i] << endl;
		if (x >= y) {
			continue;
		}
		if (d[i] == 0) {
			q.push(i);
		}
	}

	int ans = 0;
	int M = 0;
	while (!q.empty()) {
		queue<int> next;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (auto dst : g[x]) {
				--d[dst];
				if (d[dst] == 0) {
					next.push(dst);
				}
			}
			g[x].clear();
			++M;
		}
		q = move(next);
		++ans;
	}

	if (M < N * (N - 1) / 2) {
		ans = -1;
	}
	cout << ans << endl;
}
