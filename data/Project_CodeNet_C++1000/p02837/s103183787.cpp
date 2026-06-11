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
	vector<int> a(n);
	vector<vector<pair<int,int>>> saying;
	REP(i,n){
		cin >> a[i];
		vector<pair<int,int>> tmp;
		REP(j,a[i]){
			int x,y;
			cin >> x >> y;
			tmp.push_back({x-1, y}); // 0-based
		}
		saying.push_back(tmp);
	}
	
	int ans=0;
	for(int bit=0; bit<(1<<n); bit++){
		bool flag = true;
		
		REP(i,n){
			if(!(bit & (1<<i))) continue; 
			REP(j,a[i]){
				int x;
				if(bit&(1<<saying[i][j].first)) x=1;
				else x=0;
				
				if(x!=saying[i][j].second) flag = false;
			}
		}
		
		if(flag){
			chmax(ans,__builtin_popcount(bit));
		}
	}
	
	cout << ans << endl;
	
	return 0;
}