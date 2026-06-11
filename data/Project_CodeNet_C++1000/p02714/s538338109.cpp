#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int rr = 0, gg = 0, bb = 0;
	for (char c : s) {
		if (c == 'R')
			rr++;
		if (c == 'G')
			gg++;
		if (c == 'B')
			bb++;
	}
	ll res = (ll)rr * gg * bb;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			int k = 2 * j - i;
			if (s[i] != s[j] && k < n && s[i] != s[k] && s[j] != s[k])
				res--;
		}
	cout << res << '\n';

	return 0;
}

