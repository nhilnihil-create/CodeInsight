#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;

const ll mod = 1000000007;
const int max_e = 2010;
int n;
ll bit[max_e];

void init() {
	rep(i, max_e) {
		bit[i] = 0;
	}
}

void add(int key, int v) {
	for(int x = key; x < max_e; x += x & (-x)) {
		bit[x] += v;
	}
}

ll sum(int key) {
	ll ans = 0;
	for(int x = key; x > 0; x -= x & (-x)) {
		ans += bit[x];
	}
	return ans;
}




int main() {
	init();

	ll n, k;
	cin >> n >> k;

	ll a[n];
	rep(i, n) {
		cin >> a[i];
	}

	vector<ll> a0(n,0);
	vector<ll> d(n,0);

	for (int i = n - 1; i >= 0; i--) {
		a0[i] = sum(a[i] - 1);
		add(a[i], 1);
	}

	for (int i = n - 1; i >= 0; i--) {
		d[i] = sum(a[i] - 1);
		add(a[i],1);
	}
	ll first = 0;
	ll second = 0;
	for (int i = 0; i < n; i++) {
		first += a0[i];
		second += d[i];
	}

	ll d0 = second - first;
	first = first % mod;
	d0 = d0 % mod;
	ll ans = (first * k) % mod;

	ll dk =(k * (k - 1) / 2) % mod;
	ans = (ans + dk * d0) % mod;
	cout << ans << endl;

	return 0;
}
