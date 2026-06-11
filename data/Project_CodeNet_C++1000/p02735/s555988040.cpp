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
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	REP(i,h) cin >> s[i];
	
	const int INF=1e9;
	vector<vector<int>> dp(h,vector<int>(w,INF));
	if(s[0][0]=='.') dp[0][0] = 0;
	else dp[0][0] = 1;
	REP(i,h){
		REP(j,w){
			int cost=0;
			if(i!=h-1){
				if(s[i][j]=='.'&&s[i+1][j]=='#') cost=1;
				chmin(dp[i+1][j], dp[i][j]+cost);
			}
			cost = 0;
			if(j!=w-1){
				if(s[i][j]=='.'&&s[i][j+1]=='#') cost=1;
				chmin(dp[i][j+1], dp[i][j]+cost);
			}
		}
	}
	
	cout << dp[h-1][w-1] << endl;
	
	
	return 0;
}