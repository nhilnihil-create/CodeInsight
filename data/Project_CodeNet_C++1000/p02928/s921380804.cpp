#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;


int main() {

	ll N, K;
	cin >> N >> K;

	vector<ll> A(N), B(2001, 0);
	ll x = 0, y = 0;

	rep(i, N) {
		cin >> A[i];
		rep(j, i) {
			if (A[i] < A[j]) {
				x++;
			}
		}
	}

	rep(i, N) {
		rep(j, N) {
			if (A[i] < A[j]) {
				y++;
			}
		}
	}


	ll z;

	z = K * (K - 1) / 2 % mod;

	ll ans, tmp;

	ans = x * K % mod;

	tmp = (y * z) % mod;

	ans = (ans + tmp) % mod;

	cout << ans << endl;

	return 0;
}
