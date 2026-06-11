#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////

int main() {
	ll N;
	cin >> N;

	vector<ll> A(N + 1);
	repn(i, N) cin >> A[i];
	sort(++A.begin(), A.end());

	ll b = N;

	ll ans = -A[1];

	for (ll i = 2; i <= N - 1; i++) {
		ans += max(A[i], -A[i]);

		if (A[i] > 0 && b == N) { b = i; }
	}

	ans += A[N];

	stack<ll> neg;
	for (ll i = 1; i < b; i++) { neg.push(A[i]); }
	stack<ll> pos;
	for (ll i = b; i <= N; i++) { pos.push(A[i]); }

	cout << ans << endl;

	repn(i, N - 1) {
		ll x = pos.top();
		pos.pop();

		ll y = neg.top();
		neg.pop();

		if(pos.empty()) {
			cout << x << " " << y << endl;
			pos.push(x - y);
		}

		else {
			cout << y << " " << x << endl;
			neg.push(y - x);
		}
	}
	system("PAUSE");
}
