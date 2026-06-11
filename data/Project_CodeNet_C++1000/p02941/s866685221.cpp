#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) { cin >> A[i]; }
	for (int i = 0; i < N; ++i) { cin >> B[i]; }

	priority_queue<pair<int, int>> que;
	for (int i = 0; i < N; ++i) {
		if (A[i] < B[i]) {
			que.emplace( B[i], i );
		}
	}

	Int ans = 0;
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		int b = p.first, idx = p.second;
		int l = B[(idx-1+N) % N];
		int r = B[(idx+1) % N];
		
		if ((b - A[idx]) / (l + r) <= 0) { break; }
		ans += (b - A[idx]) / (l + r);
		B[idx] = A[idx] + (b - A[idx]) % (l + r);
		
		if (B[idx] <= A[idx]) { continue; }
		que.emplace( B[idx], idx );
	}

	for (int i = 0; i < N; ++i) {
		if (A[i] == B[i]) { continue; }
		cout << "-1\n";
		return 0;
	}
	cout << ans << "\n";

	return 0;
}
