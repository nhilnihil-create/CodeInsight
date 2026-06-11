#include <iostream>
#include <vector>
using namespace std;
using ll = long long ;
ll mod = 998244353 ;

ll modpow(ll a,ll b){
	ll res = 1 ;
	while(b>0){
		if(b&1) res = res*a%mod ;
		b >>= 1 ;
		a = a*a%mod ;
	}
	return res ;
}

int main(){
	ll n ; cin >> n ;
	vector<ll> d(n) ;
	for(int i=0;i<n;i++){
		ll x ; cin >> x ;
		if(i==0&&x!=0){
			cout << 0 << endl ;
			return 0 ;
		}
		if(i!=0&&x==0){
			cout << 0 << endl ;
			return 0 ;
		}
		d.at(x)++ ;
	}
	bool ok = false ;
	for(int i=0;i<n;i++){
		if(ok){
			if(d.at(i)!=0){
				cout << 0 << endl ;
				return 0 ;
			}
		}else{
			if(d.at(i)==0) ok = true ;
		}
	}
	ll ans = 1 ;
	for(int i=1;i<n;i++){
		if(d.at(i)==0) break ;
		ans = ans*modpow(d.at(i-1),d.at(i))%mod ;
	}
	cout << ans << endl ;
}

