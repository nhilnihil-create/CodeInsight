#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define ALLG(v) v.begin(), v.end() ,greater<int>()
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll GCD(ll x, ll y) { return y ? GCD(y, x % y) : x; }
ll LCM(ll x, ll y) { return x * y / GCD(x, y); }
ll GetDigit(ll num) {
	ll digit = 0;
	while (num != 0) {
		num /= 10;
		digit++;
	}
	return digit;
}

using namespace std;
int main() {
	string s, t;
	cin >> s >> t;

	int ans = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != t[i]) ans++;
	}

	cout << ans << endl;
}