#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (a > m/2 || b > n/2) {
		cout << -1;
		return 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (i <= b && j <= a) {
				cout << '1';
			} else if (i > b && j > a) {
				cout << '1';
			} else {
				cout << '0';
			}
		}
		cout << "\n";
	}
	return 0;
}
