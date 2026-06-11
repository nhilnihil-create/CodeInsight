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
	int h,w,a,b;
	cin >> h >> w >> a >> b;
	
	vector<vector<int>> ans(h,vector<int>(w,0));
	
	REP(i,h){
		REP(j,a){
			ans[i][j] = 1- ans[i][j];
		}
	}
	
	REP(i,b){
		REP(j,w){
			ans[i][j] = 1- ans[i][j];
		}
	}
	
	REP(i,h){
		REP(j,w) cout << ans[i][j];
		cout << endl;
	}
	
	return 0;
}