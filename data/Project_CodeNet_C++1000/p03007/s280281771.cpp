#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) { cin >> A[i]; }

	sort(A.begin(), A.end());
	vector<pair<int, int>> xy;
	for (int i = 1; i < N - 1; ++i) {
		if (A[i] > 0) {
			xy.emplace_back( A[0], A[i] );
			A[0] -= A[i];
		} else {
			xy.emplace_back( A.back(), A[i] );
			A.back() -= A[i];
		}
	}
	cout << A.back() - A[0] << "\n";
	for (auto p : xy) {
		cout << p.first << " " << p.second << "\n";
	}
	cout << A.back() << " " << A[0] << "\n";

	return 0;
}
