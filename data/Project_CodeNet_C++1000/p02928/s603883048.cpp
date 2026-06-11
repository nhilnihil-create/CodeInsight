#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
//#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll bit1[12345678], bit2[12345678], nn;//[1, nn]
ll sum1(ll i) {
	ll s = 0;
	while (i > 0) {
		s += bit1[i]; i -= i & -i;
	}
	return s;
}
void add1(ll i, ll x) {//iの値にxを加える
	while (i <= nn) {
		bit1[i] += x; i += i & -i;
	}
}
ll sum2(ll i) {
	ll s = 0;
	while (i > 0) {
		s += bit2[i]; i -= i & -i;
	}
	return s;
}
void add2(ll i, ll x) {//iの値にxを加える
	while (i <= nn) {
		bit2[i] += x; i += i & -i;
	}
}
ll test[12345678];
signed main() {
	ll n, k, a, cnt = 0, ans = 0; cin >> n >> k; nn = 2002;
	vector<ll> v; map<ll, ll> ma;
	for (int h = 0; h < n; h++) {
		cin >> a; test[h] = a; //cout << ' ' << sum(n + 2) << endl;
		ans += h - sum1(a); // cout << sum(a) << endl;
		add1(a, 1);
	}
	sort(test, test + n); reverse(test, test + n);
	for (int h = 0; h < n; h++) {
		cnt += h - sum2(test[h]); // cout << sum(a) << endl;
		add2(test[h], 1);
	}
	cout << (((ans % mod) * k % mod) + ((cnt % mod) * ((k * (k - 1) / 2) % mod)) % mod) % mod << endl;
	return 0;
}