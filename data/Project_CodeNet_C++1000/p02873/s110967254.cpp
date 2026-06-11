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
#define replm(i, l, r) for (ll i = l; i >= r; i--)
#define repm(i, n) repl(i, n , 0)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;

int main() {

	int i;
	string S;

	cin >> S;

	ll N;
	N = S.size() + 1;

	vector<ll>a(N, 0);
	ll count = 100;

	while (count != 0) {
		count = 0;
		repl(i, 1, N) {
			if (S[i - 1] == '<' && a[i - 1] >= a[i]) {
				a[i] = a[i - 1] + 1;
				count++;
			}
		}
		replm(i, N - 1, 1) {
			if (S[i - 1] == '>' && a[i - 1] <= a[i]) {
				a[i - 1] = a[i] + 1;
				count++;
			}
		}
	}

	ll ans = 0;

	rep(i, N) {
		ans += a[i];
	}

	cout << ans;

	return 0;

}