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
	string S;
	cin >> S;

	vector<ll> A(2*N + 1,0);

	repn(i, 2 * N) {
		if (S[i - 1] == 'B') { A[i] = 1; }
	}

	vector<ll> L(2 * N + 1);
	ll t = 0;

	repn(i, 2 * N) {
		if (t % 2 != A[i]) { L[i] = 0; t++; }
		else { L[i] = 1; t--; }
	}

	ll ans = 0;

	if (t == 0) {
		ans = 1;
		ll l = 0;

		for (ll i = 2 * N; i > 0; i--) {
			if (L[i] == 1) { l++; }
			else { ans = ans * l%MOD; l--; }
		}

		repn(i, N) {
			ans = ans * i%MOD;
		}
	}
	
	cout << ans;

	system("PAUSE");

}
