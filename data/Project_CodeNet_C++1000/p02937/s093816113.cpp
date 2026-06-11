#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 10;
int last[26][mxN];

int main() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < mxN; j++) {
			last[i][j] = -1;
		}
	}
	string s, t;
	cin >> s >> t;
	int n = s.length();
	for (int i = n - 1; i >= 0; i--) {
		int c = (int)s[i]- 'a';
		last[c][i] = i+1;
		for (int j = i-1; j >= 0; j--) {
			last[c][j] = last[c][j + 1];
		}
	}
	int n1 = t.length();
	bool ok = true;
	long long l = 0;
	long long cnt = 0;
	for (int i = 0; i < n1; i++) {
		char c = (int)t[i] - 'a';
		if (last[c][l] == -1) {
			cnt += n - l;
			l = 0;
			if (last[c][l] == -1) {
				ok = false;
				break;
			}
		}
		cnt += (long long)last[c][l] - l;
		l = last[c][l];
	}
	if (ok) cout << cnt << endl;
	else cout << -1 << endl;
	return 0;
}