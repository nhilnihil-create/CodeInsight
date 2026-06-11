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
	ll n,k;
	cin >> n >> k;
	
	const ll MOD = 1000000007;
	ll ans = 0;
	for(ll i=k; i<=n+1 ;i++){
		ll minimum = i*(i-1)/2;
		ll maximum = (2*n-i+1)*i/2;
		
		ans += maximum-minimum+1;
		ans %= MOD;
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}