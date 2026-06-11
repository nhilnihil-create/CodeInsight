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
	ll i = 1, j = 0;
	while (i < n) {
		while (i + j < n && s[j] == s[i + j]) j++;
		v[i] = j;
		if (j == 0) {
			i++;
			continue;
		}
		ll k = 1;
		while (i + k < n && k + v[k] < j) {
			v[i + k] = v[k];
			k++;
		}
		i += k;
		j -= k;
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
