#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	vector<int> list;
	int no = 1;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (no != a[i]) {
			ans++;
		}
		else {
			no++;
		}
	}

	if (ans == N) {
		ans = -1;
	}

	cout << ans << endl;
	return 0;
}