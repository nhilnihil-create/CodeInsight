#include <iostream>
#include <vector>
#include <functional>
using namespace std;

long long find_min(function<bool(long long)> solve, long long low, long long high) {
	long long ng = low, ok = high;
	while (ok - ng > 1) {
		long long mid = (ok + ng) / 2;
		if (solve(mid)) {
			ok = mid;
		} else {
			ng = mid;
		}
	}
	return ok;
}

int main() {
	long long n, k;
	cin >> n >> k;
	vector<long long> A(n), F(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> F[i];
	}
	sort(A.begin(), A.end());
	sort(F.begin(), F.end(), greater<long long>());
	auto g = [&](long long x) {
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += max(0ll, A[i] - x / F[i]);
		}
		return res;
	};
	function<bool(long long)> f = [&](long long x) {
		return g(x) <= k;
	};
	long long ans = find_min(f, -1, (long long)1e13);
	cout << ans << endl;
	return 0;
}