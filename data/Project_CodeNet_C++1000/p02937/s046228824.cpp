#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//const ll p = 1e9 + 7;
	//const ll p = 998244353;

	string s, t;
	cin >> s >> t;
	ll n = s.size(), m = t.size();

	vll cnt(26, 0);
	for (ll i = 0; i < n; i++) cnt[s[i] - 'a']++;

	for (ll i = 0; i < m; i++) {
		if (cnt[t[i] - 'a'] == 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<vll> v(26, vll(0));
	for (ll i = 0; i < n; i++) v[s[i] - 'a'].push_back(i);

	ll ans = 1, prev_idx = -1;
	for (ll i = 0; i < m; i++) {
		auto itr = upper_bound(all(v[t[i] - 'a']), prev_idx);
		if (itr == v[t[i] - 'a'].end()) {
			prev_idx = v[t[i] - 'a'][0];
			ans++;
		}
		else prev_idx = *itr;
	}
	cout << n * (ans - 1) + prev_idx + 1 << endl;
}
