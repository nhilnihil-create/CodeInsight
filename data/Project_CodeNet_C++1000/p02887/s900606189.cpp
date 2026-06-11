#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	char last;
	for (int i = 0; i < n; i++) {
		if (last != s[i]) {
			ans++;
		}
		last = s[i];
	}
	cout << ans << '\n';
}