#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e10;
const ll MAX_N = 1010;

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	if (n > k * 2) {

	}
	return fac[n] / (fac[k] * fac[n - k]);
}

ll dp[201010][2];
ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };

//long longしか使わない
//素数は1より大きい
int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll>a(n);
	rep(i, n) {
		cin >> a[i];
	}
	ll res = 0;
	ll ans = 0;
	rep(i, n) {
		for (ll j = 0;j < i;++j) {
			if (a[i] > a[j])res++;
		}
		for (ll j = i + 1;j < n;++j) {
			if (a[i] > a[j])ans++;
		}
	}
	ll total = ans + res;
	ans *= k;
	ans %= MOD;
	ll res2 = ((k - 1) * k / 2) % MOD;
	res2 *= total;
	res2 %= MOD;
	ans += res2;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}