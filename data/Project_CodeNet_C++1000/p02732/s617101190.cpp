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
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;

ll func(ll n){
	if(n<=1) return 0;
	return n*(n-1)/2;
}

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	
	vector<ll> b(200005,0);
	set<ll> s;
	
	REP(i,n){
		b[a[i]] += 1;
		s.insert(a[i]);
	}
	ll count=0;
	vector<ll> ans(n);
	
	for(ll i: s){
		count += func(b[i]);
	}
	REP(i,n){
		ans[i] = func(b[a[i]]-1) - func(b[a[i]]);
	}
	REP(i,n) ans[i] += count;
	
	REP(i,n) cout << ans[i] << endl;
	
	return 0;
}