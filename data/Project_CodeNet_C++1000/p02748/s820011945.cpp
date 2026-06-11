#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A, B, M;
	cin >> A >> B >> M;
	vector<int> a(A);
	for (int i = 0; i < A; ++i) {
		cin >> a[i];
	}
	vector<int> b(B);
	for (int i = 0; i < B; ++i) {
		cin >> b[i];
	}
	int minA = *min_element(a.begin(), a.end());
	int minB = *min_element(b.begin(), b.end());
	int ans = minA + minB;
	for (int i = 0; i < M; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		--y;
		ans = min(ans, a[x] + b[y] - c);
	}
	cout << ans << '\n';
	
	return 0;
}
