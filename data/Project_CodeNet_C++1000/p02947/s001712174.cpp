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
	vector<string> s(n);
	REP(i,n) cin >> s[i];
	REP(i,n) sort(s[i].begin(), s[i].end());
	sort(s.begin(), s.end());
	
	ll ans=0;
	
	ll r=0;
	REP(i,n-1){
		ll count=0;
		REP(j,10){
			if(s[i][j]==s[i+1][j]) count++;
			else if(r!=0){
				ans += (r*(r+1))/2;
				r = 0;
			}
		}
		if(count==10) r++;
	}
	
	if(r!=0){
		ans += (r*(r+1))/2;
	}
	
	cout << ans << endl;
	
	return 0;
}