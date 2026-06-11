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
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll gcd(ll a, ll b);


bool solve(ll f, ll s);

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n + 1, 0), b(n + 1, 0);
	ll tot = 0;

	rep(i, n) {
		cin >> a[i + 1];
		tot += a[i + 1];
	}
	
	b[1] = tot;

	rep(i, n) {
		if(i % 2 == 0) b[1] -= 2 * a[i];
	}
	
	rep(i, n - 1) {
		b[i + 2] = (2 * a[i + 1] - b[i + 1]);
	}

	rep(i, n) {
		cout << b[i + 1] << " ";
	}

	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}