#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

ll ext_gcd(ll a, ll b, ll &x, ll &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	
	ll d = ext_gcd(b, a%b, y, x);
	y -= a/b * x;
	return d;
}

ll mod_inv(ll a, ll m){
	ll x,y;
	ext_gcd(a,m,x,y);
	return (m + x%m)%m;
}

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	const ll mod = 1000000007;
	
	ll N=n, x=2;
	ll ans = 1;
	while(N > 0){
		if(N & 1){
			ans *= x;
			ans %= mod;
		}
		x *= x;
		x %= mod;
		N = N >> 1;
	}
	
	ans = (ans-1+mod)%mod;
	
	ll nca=1;
	chmin(a, n-a);
	for(ll i=1; i<=a; i++){
		nca = (nca*(n-i+1))%mod;
		nca = (nca*mod_inv(i,mod))%mod;
	}
	ans = (ans-nca+mod)%mod;
	ll ncb=1;
	chmin(b, n-b);
	for(ll i=1; i<=b; i++){
		ncb = (ncb*(n-i+1))%mod;
		ncb = (ncb*mod_inv(i,mod))%mod;
	}
	ans = (ans-ncb+mod)%mod;
	
	cout << ans << endl;
	
	return 0;
}