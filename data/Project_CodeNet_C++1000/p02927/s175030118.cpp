#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int M, D; cin >> M >> D;
	int res = 0;
	for (int m = 1; m <= M; m++) {
		for (int a = 2; a <= 9; a++) {
			for (int b = 2; b <= 9; b++) {
				if (10 * a + b <= D && a * b == m) {
					res++;
				}
			}
		}
	}
	cout << res << '\n';

	return 0;
}
