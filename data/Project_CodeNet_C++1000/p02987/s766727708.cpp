#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	sort(s.begin(), s.end());
	string ans;
	if (s[0] == s[1] && s[2] == s[3] && s[1] != s[2]) {
		ans = "Yes";
	}
	else ans = "No";
	cout << ans << endl;
	return 0;
}