#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
using V = vector<int>;
using VV = vector<vector<int>>;
int Inf = (1<<30);
ll inf = (1LL<<60);
const int MOD = 1e9 + 7;
int main() {
	ll n, k;
	cin >> n >> k;
	V a(n);
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll count = 0;
	for (i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) count++;
		}
	}
	ll count2 = 0;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] > a[j]) count2++;
		}
	}
	ll ans = 0;
	ans += count * k;
	ans %= MOD;
	ll tmp = (k * (k - 1)) / 2 % MOD;
	ans += count2 * tmp;
	ans %= MOD;
	cout << ans;
	return 0;
}