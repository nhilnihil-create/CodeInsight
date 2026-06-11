#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	int n, k, c;
	string s;
	int count = 0;
	cin >> n >> k >> c >> s;
	vector<int> d(k), f(k);
	for(int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			d[count] = i;
			count++;
			i += c;
			if (count == k) break;
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		if (s[i] == 'o') {
			count--;
			f[count] = i;
			i -= c;
			if (count == 0) break;
		}
	}
	bool nun = true;
	rep (i, k) {
		if (d[i] == f[i]) {
			cout << d[i]+1 << endl;
			nun = false;
		}
	}
	if (nun) cout << endl;
	return 0;
}
