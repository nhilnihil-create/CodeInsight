#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<Int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	Int ans = 1000;
	for (int i = 0; i + 1 < N; ++i) {
		if (a[i] >= a[i + 1]) { continue; }
		ans = ans / a[i] * a[i + 1] + ans % a[i];
	}
	cout << ans << endl;

	return 0;
}
