#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	int cnt_r = 0;
	int cnt_g = 0;
	int cnt_b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') cnt_r++;
		if (s[i] == 'G') cnt_g++;
		if (s[i] == 'B') cnt_b++;
	}
	ll cnt_error = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j <= (i + n - 1) / 2; j++) {
			if (s[i] != s[j] && s[j] != s[2 * j - i] && s[2 * j - i] != s[i]) cnt_error++;
		}
	}
	ll ans = (ll)cnt_r * cnt_g * cnt_b - cnt_error;
	cout << ans << endl;
	return 0;
}