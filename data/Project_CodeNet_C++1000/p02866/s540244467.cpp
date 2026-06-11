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
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}


const ll MOD = 998244353;
ll calc_pow(ll x, ll n){
	ll ret = 1;
	while(n>0){
		if(n & 1) ret = ret*x%MOD;
		x = x*x%MOD;
		n >>= 1;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	REP(i,n) cin >> d[i];
	
	vector<int> c(n,0);
	if(d[0]!=0){
		cout << 0 << endl;
		return 0;
	}
	
	int dmax = 0;
	REP(i,n){
		c[d[i]]++;
		chmax(dmax, d[i]);
	}
	
	
	
	if(c[0]!=1){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	FOR(i,1,dmax+1){
		if(c[i]==0){
			cout << 0 << endl;
			return 0;
		}
		ll a = calc_pow(c[i-1], c[i]);
		ans = (ans*a)%MOD;
	}
	
	cout << ans << endl;
	
	return 0;
}