#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i_length = (n); i < i_length; i++)
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int t = 0;
	string ss;
	rep(i, 2 * n) {
		if ((t + (s[i] == 'B' ? 1 : 0)) % 2 == 1) {
			ss.push_back('r'); t++;
		}
		else {
			ss.push_back('l'); t--;
		}
	}

	int r = 0;
	long long ans = 1;
	if (t != 0) ans = 0;
	rep(i, 2 * n) {
		
		if (ss[i] == 'l') {
			ans *= r--;
			ans %= MOD;
		}
		else r++;
	}
	for (int i = 1; i <= n; i++) { ans *= i; ans %= MOD; }

	cout << ans << endl;
	return 0;
}