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
	int n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	
	ll ans=0;
	const ll mod = 1000000007;
	ll two = 1;
	for(int digit=0; digit<=60; digit++){
		ll sum=0;
		REP(i,n){
			if(a[i] & (1LL<<digit)) sum++;
		}
		sum = sum*(n-sum)%mod;
		sum = (sum*two)%mod;
		ans = (ans+sum)%mod;
		two = (two*2)%mod;
		
	}
	

	ans %= mod;
	cout << ans << endl;
	
	
	return 0;
}