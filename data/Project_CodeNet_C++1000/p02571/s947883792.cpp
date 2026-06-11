#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	string s, t;
	cin >> s;
	cin >> t;
	int n = s.size(), m = t.size();
	int res = 1e9;
	for (int i = 0; i < n - m + 1; ++i) {
		int diff = 0;
		for (int j = 0; j < m; ++j)
			if (s[i + j] != t[j])
				diff++;
		res = min(res, diff);
	}
	cout << res << '\n';
}