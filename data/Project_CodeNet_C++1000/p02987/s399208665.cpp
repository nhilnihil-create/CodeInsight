#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple


signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	sort(all(s));
	if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
