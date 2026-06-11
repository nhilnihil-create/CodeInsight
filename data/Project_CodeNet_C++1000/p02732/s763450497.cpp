#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	ll cnt_total = 0;
	for (int i = 0; i <= n ; i++) {
		if (cnt[i] < 2) continue;
		else cnt_total += (ll)cnt[i] * ((ll)cnt[i] - 1) / 2;
	}
	for (int k = 1; k <= n; k++) {
		if (cnt[a[k - 1]] < 2) cout << cnt_total << endl;
		else cout << cnt_total - cnt[a[k - 1]] + 1 << endl;
	}
	return 0;
}