#include <bits/stdc++.h>
using namespace std;

void ckmax (int &x, int a) {
	x = max(x, a);
}

vector < int > zf (string s) {
	int n = s.size();
	vector < int > z(n, 0);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		ckmax(z[i], min(r - i, z[i - l]));
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			++z[i];
		if (i + z[i] > r)
			r = i + z[i], l = i;
	}
	return z;
}

signed main () {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		vector < int > z = zf(s.substr(i, n - i));
		for (int j = 0; j < int(z.size()); ++j) 
			ckmax(ans, min(z[j], j));
	}
	cout << ans << '\n';
}
