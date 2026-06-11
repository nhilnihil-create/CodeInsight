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

ll calc(ll start, ll top, ll now){
	if(top-start >= now-top){
		ll l = top - start;
		ll r = now - top -1;
		return l*(l+1)/2 + r*(r+1)/2;
	}else{
		ll l = top - start -1;
		ll r = now - top;
		return l*(l+1)/2 + r*(r+1)/2;
	}
}

int main(){
	string s;
	cin >> s;
	ll n = s.size() + 1;
	
	vector<ll> a(n,0);
	ll sum=0;
	for(int i=0; i<n-1; ++i){
		if(s[i]=='<'){
			sum++;
			chmax(a[i+1], sum);
		}else{
			sum=0;
		}
	}
	sum=0;
	for(int i=n-2; i>=0; --i){
		if(s[i]=='>'){
			sum++;
			chmax(a[i], sum);
		}else{
			sum=0;
		}
	}
	
	ll ans=0;
	REP(i,n){
		ans += a[i];
	}
	cout << ans << endl;
	
	return 0;
}