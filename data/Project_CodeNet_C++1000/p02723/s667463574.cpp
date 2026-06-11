#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << '\n';

	return 0;
}