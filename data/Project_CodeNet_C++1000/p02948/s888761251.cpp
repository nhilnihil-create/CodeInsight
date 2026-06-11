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
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}


int n,m;

int main(){
	
	cin >> n >> m;
	vector<pair<int,int>> a(n);
	vector<vector<int>> job(m+1);
	REP(i,n){
		cin >> a[i].first >> a[i].second;
		if(a[i].first <= m) job[a[i].first].push_back(a[i].second);
	}
	
	ll ans=0;
	priority_queue<int> q;
	for(int i=1; i<=m; i++){
		for(auto x:job[i]){
			q.push(x);
		}
		if(!q.empty()){
			ans += q.top();
			q.pop();
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}