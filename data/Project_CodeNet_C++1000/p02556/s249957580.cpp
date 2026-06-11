#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<int> s(N), d(N);
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		s[i] = x + y;
		d[i] = x - y;
	}
	sort(s.begin(), s.end());
	sort(d.begin(), d.end());
	int res = max(s[N - 1] - s[0], d[N - 1] - d[0]);
	cout << res << endl;
	return 0;
}