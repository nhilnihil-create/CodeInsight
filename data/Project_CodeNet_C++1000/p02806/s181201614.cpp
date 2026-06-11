#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	vector<string> s(n);
	vector<int>	t(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
	}
	string x; cin >> x;
	bool sum = false;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (sum) ans += t[i];
		if (x == s[i]) {
			sum = true;
		}
	}
	cout << ans << endl;
	return 0;
}