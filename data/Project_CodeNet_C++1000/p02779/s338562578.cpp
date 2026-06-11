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
	map<int, int> a;
	bool ok = true;
	rep(i, n) {
		int j; cin >> j;
		a[j] += 1;
		if (ok == true)
			if (a[j] == 2) ok = false;
	}

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
