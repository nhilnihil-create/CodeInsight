#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, d;
	cin >> m >> d;
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 22; j <= d; ++j) {
			if ((j % 10) * (j / 10) == i && j % 10 >= 2 && j / 10 >= 2)
				++cnt;
		}
	}
	cout << cnt << '\n';
	return 0;
}