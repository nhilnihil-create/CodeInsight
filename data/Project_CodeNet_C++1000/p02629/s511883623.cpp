#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;

	string ans = "";
	ll div = N;
	while (div != 0) {
		div--;
		int mod = div % 26;
		div /= 26;
		ans += ('a' + mod);
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}

