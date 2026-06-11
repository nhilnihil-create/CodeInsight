#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	long long n = 0, m = 0, ans = 0;
	for (int i = 0; i < S.size(); i++) {
		n++;
		if (i == S.size() - 1 && S[i] == '>') {
			ans += n * (n - 1) / 2;
			ans += max(m, n);
		} else if (i == S.size() - 1 && S[i] == '<') {
			ans += n * (n + 1) / 2;
		} else if (S[i] == S[i + 1]) {
			continue;
		} else if (S[i + 1] == '>') {
			ans += n * (n - 1) / 2;
			m = n;
			n = 0;
		} else if (S[i + 1] == '<') {
			ans += n * (n - 1) / 2;
			ans += max(n, m);
			m = n;
			n = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
