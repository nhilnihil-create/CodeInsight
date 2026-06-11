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

int main(){
	ll a,b,x;
	cin >> a >> b >> x;
	long double ans;
	
	ll L = a*a*b -x;
	
	if(L <= x){
		ans = atan((long double)(2*L)/(a*a*a))*45 /atan(1);
	}else{
		ans = atan((long double)(b*b*a)/(2*x)) *45 /atan(1);
	}
	
	printf("%.12Lf\n",ans);
	
	return 0;
}