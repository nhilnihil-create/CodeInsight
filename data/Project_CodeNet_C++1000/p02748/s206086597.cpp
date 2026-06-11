#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int A, B, M; cin >> A >> B >> M;
	vector<int> a(A), b(B);
	for (int i = 0; i < A; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}
	int ans = 1000000000;
	for (int i = 0; i < M; i++) {
		int x, y, c; cin >> x >> y >> c;
		--x;
		--y;
		int tmp = 0;
		tmp = a[x] + b[y] - c;
		ans = min(ans, tmp);
	}
	ans = min(ans, *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end()));
	cout << ans << endl;
	return 0;
}