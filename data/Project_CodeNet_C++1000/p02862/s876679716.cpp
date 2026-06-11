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
	int x,y;
	cin >> x >> y;
	const ll mod = 1000000007;
	
	if((x+y)%3!=0){
		cout << 0 << endl;
		return 0;
	}
	
	int x1=(2*y-x)/3;
	int x2=y-2*x1;
	
	if(x1<0 || x2<0 || x1+2*x2!=x || 2*x1+x2!=y){
		cout << 0 << endl;
		return 0;
	}
	
	ll ans=1;
	for(int i=1; i<=x1+x2; i++){
		ans = (ans*i)%mod;
		if(i<=x1){
			ans = (ans*mod_inv(i,mod))%mod;
		}else{
			int factor = i-x1;
			ans = (ans*mod_inv(factor,mod))%mod;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}