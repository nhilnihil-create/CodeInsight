#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	map<char,int> p;
	cin >> p['s'] >> p['p'] >> p['r'];
	string str; cin >> str;

	vector<bool> w(n + 1);

	int ans = 0;
	rep(i, k) {
		ans += p[str[i]];
		w[i] = true;
	}

	for (int i = k; i < n; i++) {
		if (str[i - k] == str[i] && w[i-k] == true) continue;
		ans += p[str[i]];
		w[i] = true;
	}

	cout << ans << endl;
	return 0;
}
