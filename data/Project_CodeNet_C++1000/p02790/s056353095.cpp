#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if (a < b) {
		rep(i, b) cout << a << flush;
	}
	else rep(i, a) cout << b << flush;

	cout << endl;
	return 0;
}
