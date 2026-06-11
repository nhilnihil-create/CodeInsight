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
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	REP(i,h) cin >> s[i];
	
	vector<vector<int>> hori(h,vector<int>(w,0)),vert(h,vector<int>(w,0));
	REP(i,h){
		int count=1;
		REP(j,w){
			if(s[i][j]=='.'){
				hori[i][j] = count;
				count++;
			}else if(s[i][j]=='#'){
				count=1;
			}
		}
	}
	REP(j,w){
		int count=1;
		REP(i,h){
			if(s[i][j]=='.'){
				vert[i][j] = count;
				count++;
			}else if(s[i][j]=='#'){
				count=1;
			}
		}
	}
	
	for(int i=h-1; i>=0; i--){
		int now=0;
		for(int j=w-1; j>=0; j--){
			if(hori[i][j]!=0){
				if(now==0){
					now = hori[i][j];
				}else{
					hori[i][j] = now;
				}
			}else{
				now = 0;
			}
		}
	}
	for(int j=w-1; j>=0; j--){
		int now=0;
		for(int i=h-1; i>=0; i--){
			if(vert[i][j]!=0){
				if(now==0){
					now = vert[i][j];
				}else{
					vert[i][j] = now;
				}
			}else{
				now = 0;
			}
		}
	}
	
	int ans=0;
	REP(i,h){
		REP(j,w){
			chmax(ans, hori[i][j]+vert[i][j]-1);
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}