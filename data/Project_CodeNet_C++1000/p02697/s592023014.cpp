#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M; cin >> N >> M;
	if (N & 1) {
		int s = 1, e = 2 * M;
		for (int i = 0; i < M; i++) {
			cout << s << ' ' << e << '\n';
			s++, e--;
		}
	}
	else {
		int mxi = 0;
		for (int i = M, j = 1; i >= 1; i--) {
			if (i & 1) {
				cout << j << ' ' << j + i << '\n';
				j++;
				mxi = max(mxi, j + i);
			}
		}
		for (int i = M, j = mxi; i >= 1; i--) {
			if (~i & 1) {
				cout << j << ' ' << j + i << '\n';
				j++;
			}
		}
	}
	return 0;
}