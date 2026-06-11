#include <bits/stdc++.h>
int N, M, V, P, A[100005], ans;
int check(int x) {
	if (A[x] >= A[P]) return 1;
	if (A[x] + M < A[P]) return 0;
	long long v = V - (P - 1) - (N - x + 1);
	if (v <= 0) return 1;
	v *= M; int lim = A[x] + M;
	for (int i = P; i < x; ++i) {
		v -= lim - A[i];
		if (v <= 0) return 1;
	}
	return 0;
}
int main() {
	std::cin >> N >> M >> V >> P;
	for (int i = 1; i <= N; ++i) std::cin >> A[i];
	std::sort(A + 1, A + N + 1), std::reverse(A + 1, A + N + 1);
	int l = 1, r = N;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	std::cout << ans << '\n';
}