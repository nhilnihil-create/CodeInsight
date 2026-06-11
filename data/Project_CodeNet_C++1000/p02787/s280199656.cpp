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

bool comp(pair<int,int> l, pair<int,int> r){
	return l.first > r.first;
}

int main(){
	int H,N;
	cin >> H >> N;
	vector<pair<int,int>> a(N);
	REP(i,N) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), comp);
	
	const ll INF = 1LL << 60;
	vector<ll> dp(H+a[0].first,INF);
	
	dp[0]=0;
	for(int i=0; i<H; i++){
		for(auto x: a){
			chmin(dp[i+x.first], dp[i]+x.second);
		}
	}
	
	ll ans = INF;
	for(int i=H; i<H+a[0].first; i++){
		chmin(ans, dp[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}