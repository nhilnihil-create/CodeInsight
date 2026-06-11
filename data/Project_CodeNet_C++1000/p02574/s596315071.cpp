#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)
#define mod 1000000007
#define ma 1000005

ll gcd(ll, ll);

int main() {
	ll n;
	ll x;
	ll gc = 0;
	bool pc = true;
	cin >> n;
	vector<ll> a(n);
	vector<ll> c(ma);
	rep(i, n) {
		cin >> a[i];
		c[a[i]]++;
	}
	for (ll i = 2; i < ma; i++) {
		int count = 0;
		for (ll j = i; j < ma; j += i) {
			count += c[j];
		}
		if (count > 1) {
			pc = false;
		}
	}
	if (pc) {
		cout << "pairwise coprime" << endl;
		return 0;
	}
	rep(i, n)gc = gcd(gc, a[i]);
	
	if (gc == 1)cout << "setwise coprime" << endl;
	else cout << "not coprime" << endl;
	return 0;
}


ll gcd(ll a, ll b) {
	if (a % b == 0)return b;
	else return gcd(b, a % b);
}