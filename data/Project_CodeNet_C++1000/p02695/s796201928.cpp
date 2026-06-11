#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int N, M, Q;
vector<int> a(55), b(55), c(55), d(55);

void func(deque<int>& A, int& ans) {
	if (A.size() >= N) {
		int tmp = 0;
		for (int i = 0; i < Q; ++i) {
			if (A[b[i]] - A[a[i]] == c[i]) { tmp += d[i]; }
		}
		ans = max(ans, tmp);
		return;
	}
	
	int a = (A.empty() ? 1 : A.back());
	for (int i = a; i <= M; ++i) {
		A.emplace_back(i);
		func(A, ans);
		A.pop_back();
	}
}

int main() {
	cin >> N >> M >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		--a[i]; --b[i];
	}

	int ans = 0;
	deque<int> A;
	func(A, ans);
	cout << ans << endl;

	return 0;
}
