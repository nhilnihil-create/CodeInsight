#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;


template <typename T>
T extGCD(T a, T b, T &x, T &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	T d = extGCD(b, a%b, y, x); // 再帰的に解く
	y -= a / b * x;
	return d;
}

// 負の数にも対応した mod 
template <typename T>
T modG(T a, T m) {
	return (a % m + m) % m;
}

// 逆元計算 
template <typename T>
T modinv(T a, T m) {
	T x, y;
	extGCD(a, m, x, y);
	return modG(x, m);
}
int main() {
	ll n;
	cin >> n;
	vector<vector<ll>> a(n);
	vector<ll> sum(60);
	for (ll i = 0; i < n; i++) {
		a[i].resize(60);
	}
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		for (ll j = 0; j < 60; j++) {
			a[i][j] = tmp % 2;
			sum[j] += a[i][j];
			tmp /= 2;
		}
	}
	ll ans = 0;
	
	for (ll i = 0; i < n; i++) {
		ll pow = 1;
		for (ll j = 0; j < 60; j++) {
			if (a[i][j] == 0) {
				ans += pow * sum[j];
			}
			else {
				ans += pow * (n - sum[j]);
			}
			ans %= mop;
			pow *= 2;
			pow %= mop;
		}
	}
	cout << (ans * modinv(2LL, mop)) % mop << endl;
}
