#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N+1);
	for (int i = 0; i < N+1; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}

	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] <= 0) {
			if (A[i + 1] <= B[i]) {
				B[i] -= A[i + 1];
				ans += A[i + 1];
				A[i + 1] = 0;
			}
			else {
				A[i + 1] -= B[i];
				ans += B[i];
				B[i] = 0;
			}
		}
		else if (A[i] <= B[i]) {
			B[i] -= A[i];
			ans += A[i];
			A[i] = 0;
			if (A[i + 1] <= B[i]) {
				B[i] -= A[i + 1];
				ans += A[i + 1];
				A[i + 1] = 0;
			}
			else {
				A[i + 1] -= B[i];
				ans += B[i];
				B[i] = 0;
			}
		}
		else {
			A[i] -= B[i];
			ans += B[i];
			B[i] = 0;
		}
	}

	cout << ans << endl;

	return 0;
}
