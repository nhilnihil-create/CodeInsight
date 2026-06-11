#include<bits/stdc++.h>
using namespace std;




/*
int main() {
	int n; cin >> n;
	string s; cin >> s;

	int l[5000] = {};
	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (s[i] == s[j - l[j]]) {
				l[j]++;
			}
			else l[j] = 0;
			ans = max(ans, min((j - i + 1) / 2, l[j]));
		}
	}

	cout << ans << endl;

	return 0;
}*/

using ULL = unsigned long long;

int main() {
	ULL Z = 0;
	ULL s[100000];

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ULL a; cin >> a;
		s[i] = a; Z ^= a;
	}
	for (int i = 0; i < n; i++) {
		s[i] &= ~Z;
	}

	for (int i = 59; i >= 0; i--) {
		ULL m = 1ull << i;
		int p = 0;
		for (; p < n; p++) {
			if ((s[p] & m) && s[p] < (m << 1))
				break;
		}if (p == n) continue;
		for (int j = 0; j < n; j++) {
			if (j == p) continue;
			if (s[j] & m)s[j] ^= s[p];
		}
	}

	ULL Y = 0; for (int i = 0; i < n; i++)Y ^= s[i];

	cout << (Z^Y) + Y << endl;

	return 0;
}
