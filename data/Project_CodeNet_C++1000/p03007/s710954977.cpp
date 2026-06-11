#include<bits/stdc++.h>

#define I inline void 

using namespace std ; 

using ll = long long ; 
using ld = long double ; 

const int N = 100 + 7 ; 

// How interesting!

int n; 

multiset<ll> mu ;

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 
	//freopen("in.in", "r" , stdin) ;
	cin >> n; 

	vector< ll > neg ; 

	for(int i = 0 ;i < n;i++){
		ll x ; 
		cin >> x; 
		mu.insert(x); 
	}
	vector<pair<ll,ll> > ans ; 

	while(mu . size() > 2){
		ll st = (*mu.begin()) ; 
		auto it = mu.rbegin() ; it--; 
		ll en = (*it) ; 
		if(en < 0)
			break ;
		ans.push_back({st , en}) ; 
		mu.erase(mu.find(st)) ; 
		mu.erase(mu.find(en)) ; 
		mu.insert(st - en) ; 
	}

	while(mu . size() > 1){
		ll st = (*mu.begin()) ; 
		ll en = (*mu.rbegin()) ; 
		ans.push_back({en , st}) ; 
		mu.erase(mu.find(st)) ; 
		mu.erase(mu.find(en)) ; 
		mu.insert(en - st) ; 
	}

	ll out = (*mu.begin()) ; 

	cout<< out <<"\n" ;
	for(auto u : ans){
		cout<< u.first <<" " << u.second <<"\n" ; 
	} 
	return 0 ; 
}