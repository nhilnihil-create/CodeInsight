#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;

const int n = 4;

vector<pair<ll,ll>> prime_factorization(ll n) {
	vector<pair<ll,ll>> pf;

	for(ll i = 2; i*i <= n; i++) {

		if(n%i != 0) continue;

		ll ex = 0;

		while(n%i == 0) {
			ex++;
			n /= i;
		}
		pf.push_back({i,ex});
	}

	if(n != 1) pf.push_back({n,1}); 
	// nが素数のときprime_factorization(n) = < {n,1} >
	return pf;
}

int main() {

	ll n; cin >> n;

	vector<pair<ll,ll>> pf = prime_factorization(n);
	ll cnt = 0;
	bool z = false;
	int tmp = 0;
	for(pair<ll,ll> p: pf) {
		ll x = p.second
;		ll i = 1;
		while(i <= x) {
			 x -= i;
			 i++;
			 cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}
