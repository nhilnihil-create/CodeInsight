#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	int n;
	string s;
	cin >> n >> s;
	char a[26];
	char c = 'A';
	for (int i = 0; i < 26; ++i) {
		a[i] = c;
		c++;
	}
	for (int i = 0; i < (int) s.size(); ++i) {
		int idx;
		for (int j = 0; j < 26; ++j)
			if (a[j] == s[i])
				idx = j;
		idx = (idx + n) % 26;
		cout << a[idx];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}
