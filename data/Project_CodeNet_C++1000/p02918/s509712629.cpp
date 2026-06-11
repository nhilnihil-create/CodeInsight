#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
using ll = long long;
using namespace std;

signed main() {
	ll n, m, cnt = 0; cin >> n >> m; string s; cin >> s;
	rep(i, s.size()) {
		if (i != 0 && s[i - 1] == s[i]) { cnt++; }
	}
	cout << min(n - 1, cnt + (m * 2)) << endl;
	return 0;
}