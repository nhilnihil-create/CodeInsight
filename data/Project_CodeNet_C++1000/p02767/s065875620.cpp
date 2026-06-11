#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; ++i) { cin >> x[i]; }

	int ans = 1e9;
	for (int i = 0; i < 133; ++i) {
		int tmp = 0;
		for (auto v : x) { tmp += (v - i)*(v - i); }
		ans = min(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}
