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


int main(){
	ll s;
	cin >> s;
	
	ll x,y,p,q;
	// x2*y3 - x3*y2 = s
	// 1e9*y3 - x3 = s
	// 1e9*(y3-1) + (1e9-x3) = s
	// 1e9*p + q = s
	// y3 = p+1
	// x3 = 1e9 - q
	p = s/(ll)1e9;
	q = s%(ll)1e9;
	if(p==(ll)1e9){
		y = p;
		x = 0;
	}else{
		y = p+1;
		x = (ll)1e9 - q;
	}
	cout << "0 0 ";
	cout << (int)1e9 << " 1 ";
	cout << x << " " << y << endl;
	
	return 0;
}