#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);


	int a[10][10] = {}; //begin end;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str = to_string(i);
		int ib = ctoi(str[0]);
		int ie = ctoi(str[str.length() - 1]);
		a[ib][ie] += 1;

	}

	ll ans = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {

			ans += a[i][j] * a[j][i];

		}

	}

	cout << ans << endl;

	return 0;
}
