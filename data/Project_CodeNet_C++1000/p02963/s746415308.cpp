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
	ll S;
	cin >> S;

	ll l = 0;
	ll r = 1000000001;

	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (m*m > S - 1) { r = m; }
		else { l = m; }
	}

	ll M=r;

	ll x1 = 0;
	ll y1 = 0;

	ll N, x2, y3;

	if (M*(M - 1) >= S) {
		N = M * (M - 1);
		x2 = M;
		y3 = M - 1;
	}
	
	else { N = M * M; x2 = M; y3 = M; }

	ll y2 = 1;
	ll x3 = N - S;

	cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;

	system("PAUSE");

}



