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
	ll n,m,in;
	cin >> n >> m;
	priority_queue<ll> price;
	REP(i,n){
		cin >> in;
		price.push(in);
	}
	
	ll goods;
	REP(i,m){
		goods = price.top();
		price.pop();
		price.push(goods/2);
	}
	
	ll ans=0;
	while(!price.empty()){
		ans += price.top();
		price.pop();
	}
	cout << ans << endl;
	
	
	
	return 0;
}