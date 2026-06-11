#include <bits/stdc++.h>
using namespace std;

string s;
int n, k;
long long ans = 0;

int main() {
	cin >> s >> k;
	n = s.size();
	int h = 0, f = n - 1;
	while (s[h] == s[h + 1])
		h++;

	if (h == n - 1) {
		cout << (long long) n * k / 2 << endl;
		return 0;
	}

	while (s[f] == s[f - 1])
		f--;
	for (int i = h + 1, c = 1; i < f; i++) {
		if (i + 1 == f || s[i + 1] != s[i]) {
			ans += c / 2;
			c = 1;
		} else
			c++;
	}
	ans *= k;
	ans += (h + 1) / 2 + (n - f) / 2;
	if (s[0] == s[n - 1])
		ans += (long long) (h + 1 + n - f) / 2 * (k - 1);
	else
		ans += (long long) ((h + 1) / 2 + (n - f) / 2) * (k - 1);
	cout << ans << endl;
}
