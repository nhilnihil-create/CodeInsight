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
	ll n,k;
	cin >> n >> k;
	const ll mod = 1000000007;
	
	ll ans = 0;
	for(ll i=1; i<=k; i++){
		// (k-i) tama
		// (i-1) shikiri
		// (k-1)!/ (k-i)! ((i-1)!)
		ll blue = 1;
		for(ll j=(k-i)+1; j<=(k-1); j++){
			blue *= j;
			blue %= mod;
		}
		for(ll j=1; j<=(i-1); j++){
			blue *= mod_inv(j,mod);
			blue %= mod;
		}
		
		// (n-k-i+1) tama
		// i shikiri
		// (n-k+1)! / (n-k-i+1)!   ((i)!)
		ll red = 1;
		for(ll j=1; j<=i; j++){
			red *= (n-k+1)-j+1;
			red %= mod;
		}
		for(ll j=1; j<=i; j++){
			red *= mod_inv(j,mod);
			red %= mod;
		}
		
		ans = (blue*red)%mod;
		cout << ans << endl;
	}
	
	
	return 0;
}