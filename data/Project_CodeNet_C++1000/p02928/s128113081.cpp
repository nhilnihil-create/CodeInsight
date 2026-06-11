#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll dv = 1000000007;


int main() {
  ll n,k;cin >> n >> k;
	vector<ll> a(n);
	rep(i,n) cin >> a.at(i);

	ll base = 0; // 与えられた数列の転倒数
	rep(i,n-1){
		for(ll j=i+1;j<n;++j){
			if( a.at(i) > a.at(j) ) ++base;
		}
	}
	
	ll base2 = 0; //与えられた数列2つから一つずつ選んで作れる転倒した組の数
	for(ll i=0;i<n;++i){
		for(ll j=0;j<n;++j){
			if( a.at(i) > a.at(j) ) ++base2;
		}
	}

	ll ans = base*k%dv;
	ans += k*(k-1)/2%dv*base2%dv;

	// cout << "base : " << base << endl;
	// cout << "base2 : " << base2 << endl;

	cout << ans%dv << endl;

	return 0;
}