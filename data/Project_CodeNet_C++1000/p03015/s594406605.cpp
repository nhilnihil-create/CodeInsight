#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	const int mod = 1e9 + 7;
	string st;
	cin >> st;
	int n = st.size();
	long long e[n], s[n], l[n];
	if (st[ n - 1] == '0') {
		e[n - 1] = 1;
		s[n - 1] = 0;
		l[n - 1] = 2;
	}
	else {
		e[n - 1] = 2;
		s[n - 1] = 1;
		l[n - 1] = 0;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (st[i] == '0') {
			e[i] = e[i + 1];
			s[i] = s[i + 1];
			l[i] = 2 * e[i + 1] + 2 * s[i + 1] + 3 * l[i + 1];
		}
		else {
			e[i] = 2 * e[i + 1];
			s[i] = e[i + 1] + 3 * s[i + 1] + l[i + 1];
			l[i] = 2 * l[i + 1];
		}
		e[i] %= mod;
		s[i] %= mod;
		l[i] %= mod;
	}
	cout << (e[0] + s[0]) % mod << '\n';
	return 0;
}