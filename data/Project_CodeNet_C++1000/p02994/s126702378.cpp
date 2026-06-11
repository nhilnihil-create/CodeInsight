#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, L; cin >> N >> L;
	int res = 0;
	pair<int, int> a[N];
	for (int i = 0; i < N; i++) {
		int x = L + i;
		res += x;
		a[i] = make_pair(abs(x), x);
		// cout << x << endl;
	}

	sort(a, a + N);
	// cout << res - a[0];
	// for (int i = 1; i < N; i++) cout << a[i].first << a[i].second << endl;
	cout << res - a[0].second;
	return 0;
}

