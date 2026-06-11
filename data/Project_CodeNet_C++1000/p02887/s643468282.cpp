#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	int n; cin >> n;
	string s; cin >> s;
	s = '$' + s;
	int ans = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) ans++;
	}
	cout << ans << '\n';
}
