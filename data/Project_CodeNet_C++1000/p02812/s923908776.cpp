#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;




int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);


	int n; cin >> n;

	string str;
	cin >> str;
	int S = str.length();

	int ans = 0;

	rep(i, S - 2) {
		if (str.substr(i, 3) == "ABC") ans++;

	}

	cout << ans << endl;

	return 0;
}
