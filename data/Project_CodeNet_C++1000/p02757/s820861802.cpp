#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	ll n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	ll ans = 0;
	if (10 % p == 0) {
		rep(i, n) {
			if ((s[i] - '0') % p == 0) ans += i + 1;
		}
		cout << ans << endl;
		return 0;
	}
	ll ten = 1;
	reverse(s.begin(), s.end());
	vector<ll> m(n + 1, 0);
	REP(i, n) {
		m[i] = m[i - 1] + ten * (s[i - 1] - '0');
		m[i] %= p;
		ten *= 10;
		ten %= p;
	}
	vector<ll> t(p, 0);
	rep(i, n + 1) {
		t[m[i]]++;
	}
	rep(i, p) {
		ans += t[i] * (t[i] - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}
