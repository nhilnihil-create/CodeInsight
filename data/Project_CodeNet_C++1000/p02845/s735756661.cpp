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
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	
	const ll MOD = 1e9+7;
	int c[3] ={-1,-1,-1};
	ll ans=1;
	REP(i,n){
		int count=0;
		REP(j,3){
			if(a[i]==c[j]+1){
				count++;
			}
		}
		ans = ans*count%MOD;
		REP(j,3){
			if(a[i]==c[j]+1){
				c[j] = a[i];
				break;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}