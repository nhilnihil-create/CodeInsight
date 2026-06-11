#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n, a;
multiset<int> st;
vector<int> vec;

signed main() {
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		cin >> a;
		st.insert(a);
	}
	vec.push_back(*st.rbegin());
	st.erase(st.lower_bound(*st.rbegin()));
	for (int i = 0; i < n; i++) {
		vector<int> ve;
		for (int j = 0; j < (int)vec.size(); j++) {
			if (st.lower_bound(vec[j]) == st.begin()) {
				cout << "No" << endl;
				return 0;
			}
			ve.push_back(*--st.lower_bound(vec[j]));
			st.erase(--st.lower_bound(vec[j]));
		}
		for (int j = 0; j < (int)ve.size(); j++)vec.push_back(ve[j]);
	}
	cout << "Yes" << endl;
}
