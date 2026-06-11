#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); i++) {
		if (s[i-1] == s[i]) {
			cout << "Bad" << '\n';
			return 0;
		}
	}
	cout << "Good" << '\n';
	return 0;
}