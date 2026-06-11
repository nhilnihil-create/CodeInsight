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

 ll gcd(ll a, ll b){
 	if(b==0) return a;
 	
	return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return a * b / gcd(a, b);
}

int main(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	ll U = b-a+1;
	ll cdiv = b/c - (a-1)/c;
	ll ddiv = b/d - (a-1)/d;
	ll cd_lcm = lcm(c,d);
	ll candd = b/(cd_lcm) - (a-1)/(cd_lcm);
	ll ans = U - (cdiv+ddiv-candd);
	cout << ans << endl;
	
	return 0;
}