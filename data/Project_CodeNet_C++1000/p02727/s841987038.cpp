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
	ll x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	vector<pair<ll,ll>> p;
	ll in;
	REP(i,a){
		cin >> in;
		p.push_back(make_pair(-1*in,1));
	}
	REP(i,b){
		cin >> in;
		p.push_back(make_pair(-1*in,2));
	}
	REP(i,c){
		cin >> in;
		p.push_back(make_pair(-1*in,3));
	}
	
	sort(p.begin(),p.end());
	
	ll ans=0, x_count=0, y_count=0;
	ll k = 0;
	for(ll i=0; i<x+y+k; i++){
		if(x_count<x && p[i].second==1){
			ans += p[i].first;
			x_count++;
		}else if(y_count<y && p[i].second==2){
			ans += p[i].first;
			y_count++;
		}else if(p[i].second==3){
			ans += p[i].first;
		}else{
			k++;
		}
	}
	
	cout << abs(ans) << endl;
	
	return 0;
}