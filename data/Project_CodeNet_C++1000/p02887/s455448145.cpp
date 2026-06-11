#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int ans = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) ans++;
	}
	cout << ans << endl;
	return 0;
}