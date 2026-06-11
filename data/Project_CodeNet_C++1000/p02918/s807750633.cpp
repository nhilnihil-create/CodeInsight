// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	k = 2 * k;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i - 1]) {
			ans++;
		}
		else if(k) {
			k--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
