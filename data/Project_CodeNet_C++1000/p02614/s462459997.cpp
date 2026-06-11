#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n, m, k;
	cin >> n >> m >> k;
	char mat[n][m];
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == '#') {
				total++;
			}
		}
	}
	int n1 = pow(2, n), m1 = pow(2, m), ans = 0;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			bitset<6> b1(i);
			bitset<6> b2(j);

			int count = 0;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					if (b1[k] == 1 || b2[l] == 1)
						continue;
					if (mat[k][l] == '#')
						count++;
				}
			}
			if (count == k)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
