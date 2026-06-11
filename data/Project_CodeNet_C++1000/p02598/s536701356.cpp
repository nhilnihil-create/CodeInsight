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

ll n,k,amax=0;
vector<ll> a;

ll f(ll t){
	ll count=0;
	for(ll x: a){
		count += max((ll)0, (ll)ceil((double)x/t)-1);
	}
	return count;
}


int main(){
	cin >> n >> k;
	a.resize(n);
	REP(i,n){
		cin >> a[i];
		chmax(amax, a[i]);
	}
	ll ok,ng,mid;
	ok = amax;
	ng = 0;
	while(abs(ok-ng)>1){
		mid = (ok+ng)/2;
		
		if(f(mid) <= k) ok = mid;
		else ng = mid;
	}
	
	
	cout << ok << endl;
	
	
	return 0;
}