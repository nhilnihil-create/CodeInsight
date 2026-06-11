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
	const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n;
	cin >> n;
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vll dp(n, 0);
	map<ll, ll> mp;
	if (a[0] == 0) {
		dp[0] = 3;
		mp[0] = 2;
		mp[1] = 1;
	}

	for (ll i = 1; i < n; i++) {
		dp[i] = dp[i - 1] * mp[a[i]] % p;
		mp[a[i]]--;
		mp[a[i] + 1]++;
	}
	cout << dp[n - 1] << endl;
}
