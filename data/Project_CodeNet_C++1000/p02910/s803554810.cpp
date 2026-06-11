#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	string  ans = "Yes";
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			if (s[i] == 'L') ans = "No";
		}
		else {
			if (s[i] == 'R') ans = "No";
		}
	}
	cout << ans << endl;
	return 0;
}