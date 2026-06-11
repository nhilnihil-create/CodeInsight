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
	string s;
	cin >> n >> s;
	
	
	int a[10][10][10]={};
	int b[10][10] = {};
	int last[10];
	REP(i,10) last[i] = -1;
	vector<vector<int>> exist(n+1, vector<int>(10,0));
	
	REP(i,n){
		int num=s[i]-'0';
		
		REP(j,10){
			if(exist[i][j]){
				REP(k,10){
					if(exist[last[j]][k]){
						a[k][j][num] = 1;
					} 
				}
			}
		}
		
		REP(j,10){
			exist[i+1][j] = exist[i][j];
		}
		if(exist[i+1][num]==0){
			exist[i+1][num]=1;
		}
		last[num] = i;
			
	}	
	
	int ans=0;
	REP(i,10) REP(j,10) REP(k,10) ans += a[i][j][k];
	
	cout << ans << endl;
	
	return 0;
}