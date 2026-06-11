#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
//const ll p = 1e9 + 7;
//const ll p = 998244353;
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n, p;
	string s;
	cin >> n >> p >> s;

	if (p == 2 || p == 5) {
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			if ((s[i] - '0') % p == 0) ans += i + 1;
		}
		cout << ans << endl;
	}
	else {
		vll remcnt(p, 0);
		remcnt[0]++;
		ll rem = 0, x = 1;
		for (ll i = n - 1; i >= 0; i--) {
			rem += (s[i] - '0') * x % p;
			rem %= p;
			remcnt[rem]++;
			x *= 10;
			x %= p;
		}
		ll ans = 0;
		for (ll i = 0; i < p; i++) {
			ans += remcnt[i] * (remcnt[i] - 1) / 2;
		}
		cout << ans << endl;
	}
}
