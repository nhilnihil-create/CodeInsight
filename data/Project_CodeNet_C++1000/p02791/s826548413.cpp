#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int min = a[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (min > a[i]) {
			cnt++;
			min = a[i];
		}
	}

	cout << cnt << endl;


}
