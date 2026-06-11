#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	string ans = "Good";
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) ans = "Bad";
	}
	cout << ans << endl;
	return 0;
}