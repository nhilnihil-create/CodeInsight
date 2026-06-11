#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ans = -2e18;
	ans = max(a * c, ans);
	ans = max(a * d, ans);
	ans = max(b * c, ans);
	ans = max(b* d, ans);
	cout << ans << '\n';
	return 0;
}