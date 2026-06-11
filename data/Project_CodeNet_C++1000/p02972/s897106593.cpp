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

vector<int> to[200005];
vector<int> ans;
ll gcd(ll a, ll b);

int main() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	rep(i, n) cin >> a[i + 1];
	
	vector<int> b(n + 1);
	
	ll sum = 0;

	for (int i = n; i > 0; i--) {
		ll j = n / i, tot = 0;
		while (j != 1) {
			tot += b[j * i];
			j--;
		}
		if (tot % 2 != a[i]) {
			b[i] = 1;
			sum++;
		}
	}

	if (sum == 0) cout << 0;
	else {
		cout << sum << endl;
		repl(i, 1, n + 1) {
			if (b[i] == 1) cout << i << " ";
		}
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