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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	if (N == 1) cout << 0 << '\n';
	else {
		ll a = 1, b = 1, c = 1;
		for (int i = 0; i < N; i++) {
			a *= 10;
			c *= 9;
			b *= 8;
			a %= mod;
			b %= mod;
			c %= mod;
		}
		cout << (a - 2 * c + b + 2*mod) % mod << '\n';
	}
	return 0;
}