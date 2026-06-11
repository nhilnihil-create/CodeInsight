#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)















int main() {
	ll n, m, v, p;
	cin >> n >> m >> v >> p;
	vector<ll> a(n);
	REP(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	ll l = 0, r = n;
	auto f = [&](ll x) {
		if (x < p) return true;
		if (a[x] + m < a[p - 1]) return false;
		ll sum = 0;
		REP(i, n) {
			if (i < p - 1) sum += m;
			else if (i < x) sum += a[x] - a[i] + m;
			else sum += m;
		}
		return m * v <= sum;
	};
	while (r - l > 1) {
		ll x = (l + r) / 2;
		if (f(x)) l = x;
		else r = x;
	}
	cout << l + 1 << endl;
}