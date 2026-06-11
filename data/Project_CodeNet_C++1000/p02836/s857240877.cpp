/**
 *	author:		Yoseph Weissman
 *	created:	17.06.2020 09:59:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0, j = (int)s.length()-1; i < j; ++i, --j) {
		if (s[i] != s[j])
			++cnt;
	}
	cout << cnt << "\n";
	return 0;
}
