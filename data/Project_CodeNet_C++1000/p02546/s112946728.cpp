#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 5, MOD = 1e9 + 7;
const ll INF = 1e18 + 17;

void solve() {
	string s;
	cin >> s;
	if (s.back() != 's') s += 's';
	else {
		s += "es";
	} 
	cout << s;
}

main() {
	ios :: sync_with_stdio(0);		
	cin.tie(0);
	int tt = 1;
	//cin >> tt;
	while (tt--) {
		solve();
		cout << '\n';
	} 
	return 0;
}