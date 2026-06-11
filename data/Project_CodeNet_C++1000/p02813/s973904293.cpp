#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n), b(n);

	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	int fact[10];
	fact[0] = 1;
	for (int i = 1; i < 10; i++) fact[i] = fact[i-1] * i;
	int A = 0;
	bool use[10] = {};
	rep(i, n-1) {
		
		int cnt = 0;
		for (int j = 1; j < 10; j++) {
			if (a[i] == j) break;
			if (use[j] == false) cnt++;
		}

		A += fact[n - 1 - i] * cnt;
		use[a[i]] = true;
	}
	int B = 0;
	rep(i, 10) use[i] = false;


	rep(i, n-1) {
		int cnt = 0;
		for (int j = 1; j < 10; j++) {
			if (b[i] == j) break;
			if (!use[j])cnt++;
		}

		B += fact[n - 1 - i] * cnt;
		use[b[i]] = true;
	}

	cout << abs(A - B) << endl;


	return 0;
}
