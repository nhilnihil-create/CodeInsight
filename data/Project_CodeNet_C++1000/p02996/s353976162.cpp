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
	ll N;
	cin >> N;
	vector<pair<ll,ll>> a(N);
	REP(i,N) cin >> a[i].second >> a[i].first;
	
	sort(a.begin(),a.end());
	
	ll time = 0;
	REP(i,N){
		if(time+a[i].second > a[i].first){
			cout << "No" << endl;
			return 0;
		}
		time += a[i].second;
	}
	cout << "Yes" << endl;
	
	return 0;
}