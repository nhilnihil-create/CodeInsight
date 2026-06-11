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
	vector<pair<int,int>> x(n);
	REP(i,n){
		cin >> x[i].first >> x[i].second;
	}
	
	map<pair<int,int>,int> m;
	REP(i,n){
		REP(j,n){
			if(i==j) continue;
			
			int dx = x[i].first - x[j].first;
			int dy = x[i].second - x[j].second;
			m[make_pair(dx,dy)]++;
			
		}
	}
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	
	int ans=50;
	for(auto l:m){
		// i -> j 
		int res = 0;
		//vector<vector<int>> ok(n,vector<int>(n,0));
		vector<pair<int,int>> check(n,{0,0});
		REP(i,n){
			REP(j,n){
				if(i==j) continue;
				
				if(check[i].second == 1 || check[j].first == 1) continue;
				
				int dx = x[i].first - x[j].first;
				int dy = x[i].second - x[j].second;
				if(dx==l.first.first && dy==l.first.second){
					check[i].second =1;
					check[j].first = 1;
					res++;
				}
				
			}
		}
		
		chmin(ans, n-res);
	}
	
	cout << ans << endl;
	
	return 0;
}