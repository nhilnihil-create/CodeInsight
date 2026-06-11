#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const ll MOD = 1e9 + 7;

ll pw(ll a, ll p) {
	ll res = 1;
	while (p > 0) {
		if (p & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		p /= 2;
	}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> have(k + 1);
	ll ans = 0;
	for (ll i = k; i >= 1; i--) {
		ll cur = pw(k / i, n);
		for (int j = i + i; j <= k; j += i) {
			cur -= have[j];
			if (cur < 0)cur += MOD;
		}
		have[i] = cur;
		cur = (cur * i) % MOD;
		ans = (ans + cur) % MOD;
	}
	cout << ans;
}