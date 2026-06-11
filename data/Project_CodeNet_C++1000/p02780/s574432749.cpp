#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = ll(1e18)+1;

int main() {
	ll n,k;
	cin >> n >>k;

	vector<ll> p(n);

	rep (i,n) {
		cin >> p[i];
	}

	ll ma = 0;

	rep(i,k) {
		ma += p[i];
	}

	ll Max = ma;

	rep(i, n-k) {
		ma += p[i+k];
		ma -= p[i];
		Max = max(Max, ma);
	}

	Max += k;
	double e = Max;
	cout << fixed << setprecision(6) << e/2 << endl;
	return 0;
}