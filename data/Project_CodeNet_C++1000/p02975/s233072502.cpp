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

	vector<ll> a(N);
	rep(i, N) cin >> a[i];

	string ans = "Yes";

	if (N % 3 != 0) { 
		rep(i, N) {
			if (a[i] != 0) { ans = "No"; }
		}
		 }
	else {

		ll M = N / 3;
		sort(a.begin(), a.end());

		rep(i, N) {
			ll j = i % M;
			if (a[i] != a[i - j]) { ans = "No"; }
			//cout << a[i] << a[i - j];
		}

		if ((a[0] ^ a[M]) != a[2 * M]) { ans = "No"; }
	}
	
	cout << ans;
	system("PAUSE");

}



