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

const ll mod = 1e9 + 7;
ll cache[2200];

ll solve(int n) {
	if (n <= 2) return 0;
	ll& ret = cache[n];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = 3; i <= n; i++) {
		if (n - i >= 3) ret = (ret + solve(n - i)) % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll S; cin >> S;
	memset(cache, -1, sizeof(cache));
	cout << solve(S) << '\n';
	return 0;
}