#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

void z_alg(string s, vll &v) {
	ll n = s.size();
	v[0] = n;
	ll cnt = 0;
	for (ll i = 1; i < n; i++) {
		for (ll j = i + cnt; j < n; j++) {
			if (s[j] != s[j - i]) {
				cnt = j - i;
				break;
			}
			if (j == n - 1) cnt = n - i;
		}
		v[i] = cnt;
		if (cnt == 0) continue;
		for (ll j = i + 1; j < n; j++) {
			if (j - i + v[j - i] < cnt) {
				v[j] = v[j - i];
				if (j == n - 1) return;
			}
			else {
				cnt -= j - i;
				i = j - 1;
				break;
			}
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n;
	string s;
	cin >> n >> s;

	vector<vll> v(n);
	for (ll i = 0; i < n; i++) {
		v[i].resize(n - i);
		string t = s.substr(i);
		z_alg(t, v[i]);
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n - i; j++) {
			ll x = min(j, v[i][j]);
			ans = max(ans, x);
		}
	}

	cout << ans << endl;
}
