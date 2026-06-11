#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int n = s.size() + 1;
	vector<int> x(n);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '<') x[i + 1] = max(x[i + 1], x[i] + 1);
	}
	for (int i = n - 1; i > 0; i--) {
		if (s[i - 1] == '>') x[i - 1] = max(x[i - 1], x[i] + 1);
	}
	ll ans = 0;
	rep(i, n) ans += x[i];
	cout << ans << endl;
	return 0;
}