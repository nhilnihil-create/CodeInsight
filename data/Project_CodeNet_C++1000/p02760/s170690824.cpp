#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long
#define ld long double

using namespace std;

int main () {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a[3][3], n, m[3][3];
	memset(m, 0, sizeof(m));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	cin >> n;
	int b[n];
	cina(b, n);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < n; ++k) {
				if (a[i][j] == b[k])
					m[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (m[i][0] && m[i][1] && m[i][2]) {
			cout << "Yes";
			return 0;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (m[0][i] && m[1][i] && m[2][i]) {
			cout << "Yes";
			return 0;
		}
	}
	if ((m[0][0] && m[1][1] && m[2][2]) || (m[0][2] && m[1][1] && m[2][0])) {
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}