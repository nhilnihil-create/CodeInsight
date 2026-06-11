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

int main() {
	
	ll N;
	cin >> N;

	vector<p> A(N);
	ll C, R, S, T;

	rep(i, N){
		cin >> C >> R;
		S = C - R;
		T = C + R;
		A[i].first = T;
		A[i].second = S;
	}

	sort(A.begin(), A.end());

	ll tmp = -1e9, ans = 0;

	rep(i, N) {
		if (tmp <= A[i].second) {
			ans++;
			tmp = A[i].first;
		}
	}

	cout << ans;

	return 0;
}


ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}