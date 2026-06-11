#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int K, N;
	cin >> K >> N;

	vector<int> A(N);

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	vector<int> div(N);
	int j = 0;
	for (int i = 0; i < A.size() - 1; ++i) {
		div[j++] = A[i + 1] - A[i];
	}
	div[N - 1] = K - A[A.size() - 1] + A[0];

	int tmp = 0;
	int ans = 0;
	for (int i = 0; i < div.size(); ++i) {
		tmp = max(tmp, div[i]);
		ans += div[i];
	}

	cout << ans - tmp << endl;
	return 0;
}
