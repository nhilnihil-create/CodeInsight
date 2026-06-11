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

ll N, A, B, C, D;
string S;

bool solve() {
	for (ll i = A + 1; i < C - 1; i++) {
		if (S[i] == '#'&&S[i + 1] == '#') { return 0; }
	}

	for (ll i = B + 1; i < D - 1; i++) {
		if (S[i] == '#'&&S[i + 1] == '#') { return 0; }
	}

	if (C < D) { return 1; }

	for (ll i = B; i <= D; i++) {
		if (S[i - 1] == '.'&&S[i] == '.'&&S[i + 1] == '.') { return 1; }
	}

	return 0;
}


int main() {
	cin >> N >> A >> B >> C >> D;
	cin >> S;
	S = '?' + S;

	ll b = solve();

	if (b == 1) { cout << "Yes"; }
	else { cout << "No"; }

	
	system("PAUSE");

}



