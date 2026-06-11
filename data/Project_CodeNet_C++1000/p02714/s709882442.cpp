#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	int n;
	ll ans = 1;
	string s;
	cin >> n >> s;
	vector<ll> c(3);
	rep(i, n) {
		if (s[i] == 'R') c[0]++;
		else if (s[i] == 'G') c[1]++;
		else c[2]++;
	}
	rep(i, 3) ans *= c[i];
	rep(i, n) rep(j, i) {
		int k = i + (i - j);
		if (k < n) {
			if(s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
