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

	ll n, k;
	cin >> n >> k;
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vll sum(n + 1, 0);
	for (ll i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + a[i];
		sum[i + 1] %= k;
	}//sum[i] := (aの先頭i項の和) % k

	vll v(n + 1, 0);
	for (ll i = 0; i < n; i++) {
		v[i + 1] = sum[i + 1] - i - 1;
	}

	//for (ll i = 0; i < n; i++) cout << v[i + 1] << endl;

	ll ans = 0;
	unordered_map<ll, ll> mp;
	mp[v[0]]++;
	for (ll j = 1; j <= n; j++) {
		if (j >= k) mp[v[j - k]]--;
		ans += mp[v[j]];
		ans += mp[v[j] + k];
		mp[v[j]]++;
	}
	cout << ans << endl;
}
