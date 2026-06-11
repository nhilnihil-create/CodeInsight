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

// r:0 s:1 p:2
int kachi(char c){
	if(c=='r') return 2;
	else if(c=='s') return 0;
	else return 1;
}
int aiko(char c){
	if(c=='r') return 0;
	else if(c=='s') return 1;
	else return 2;
}
int make(char c){
	if(c=='r') return 1;
	else if(c=='s') return 2;
	else return 0;
}

int main(){
	int n,k;
	int point[3];
	string t;
	cin >> n >> k;
	REP(i,3) cin >> point[i]; 
	cin >> t;
	
	
	vector<vector<ll>> dp(n,vector<ll>(3,0));
	ll ans=0;
	
	for(int i=0; i<k; ++i){
		for(int j=i; j<n; j+=k){
			if(j<k){
				dp[j][kachi(t[j])] = point[kachi(t[j])];
			}else{
				REP(m,3){
					if(m!=kachi(t[j])) chmax(dp[j][kachi(t[j])], dp[j-k][m]+point[kachi(t[j])]);
					if(m!=aiko(t[j])) chmax(dp[j][aiko(t[j])], dp[j-k][m]);
					if(m!=make(t[j])) chmax(dp[j][make(t[j])], dp[j-k][m]);
				}
				
			}
		}
		
	}
	
	REP(i,k){
		ll a=0;
		REP(j,3){
			chmax(a, dp[n-1-i][j]);
		}
		ans += a;
	}
	cout << ans << endl;
	
	
	
	return 0;
}