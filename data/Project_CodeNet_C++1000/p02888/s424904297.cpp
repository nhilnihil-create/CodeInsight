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
	ll n;
	cin >> n;
	vector<ll> L(n);
	REP(i,n) cin >> L[i];
	sort(L.begin(),L.end());
	
	int ans=0;
	for(int i=0; i<=n-3; ++i){
		for(int j=i+1; j<=n-2; ++j){
			int ue,shita;
			int ok = j;
			int ng = n;
			
			while(abs(ok-ng)>1){
				int mid = (ok+ng)/2;
				if(L[i]+L[j]>L[mid]) ok=mid;
				else ng = mid;
			}
			ue = ok;
			
			ok = n;
			ng = j;
			while(abs(ok-ng)>1){
				int mid = (ok+ng)/2;
				if(L[i]+L[mid]>L[j]) ok=mid;
				else ng = mid;
			}
			shita = ok;
			if(ue!=j && shita!=n){
				ans += ue-shita+1;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}