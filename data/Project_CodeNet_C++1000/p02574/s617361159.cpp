#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<ll> getFactors(ll n) {
	set<ll> res;
	while(n%2==0) {
		res.insert(2);
		n >>= 1;
	}
	for(int i = 3; i*i <= n; i+=2) {
		while(n%i==0) {
			res.insert(i);
			n /= i;
		}
	}
	if(n > 2)
		res.insert(n);
	return res;
}
bool ispairwise(vector<ll>& a) {
	ll n = a.size();
	set<ll> factors;
	for(int i = 0; i < n; i++) {
		set<ll> get = getFactors(a[i]);
		for(auto x : get) {
			if(factors.count(x))
				return false;
			factors.insert(x);
		}
	}
	return true;
}

bool issetwise(vector<ll>& a) {
	ll res = __gcd(a[0], a[1]);
	for(int i = 2; i < a.size(); i++) {
		res = __gcd(res, a[i]);
	}
	if(res == 1)
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n); for(auto& x : a) cin >> x;

	bool pairwise = ispairwise(a);
	if(pairwise) {
		cout << "pairwise coprime\n";
		return 0;
	}
	bool setwise = issetwise(a);
	if(setwise) {
		cout << "setwise coprime\n";
		return 0;
	}
	cout << "not coprime\n";
	return 0;

}
