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
	ll w,h,x,y;
	cin >> w >> h >> x >> y;
	
	printf("%.10Lf", (long double)w/2.0 * h);
	if(2*x==w && 2*y==h) printf(" 1\n");
	else  printf(" 0\n");
	
	return 0;
}