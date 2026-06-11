#include<bits/stdc++.h>
//#pragma GCC optimize("trapv")
#define I inline void 
#define S struct 
#define vi vector<int> 

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 5e3 + 7 , mod = 1e9 + 7 ; 


// How interesting!

ll n , k ; 

ll ans ; 

ll a[N] , b[N] ;

vector<bool> vis(N , 0) ; 

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ;

	cin >> n >> k ; 
	ll mx = -1e18 ; 
	for(int i = 0 ;i < n;i++){
		cin >> a[i] ; 
		a[i] -- ; 
	}

	for(int i = 0;i < n;i ++){
		cin >> b[i] ; 
		mx = max(mx , b[i]) ; 
	}
	if(mx <= 0)
		return cout<< mx , 0 ; 
	ll out  = -1e18 ; 
	for(int i = 0 ;i < n;i ++){
		ll cur = a[i] ; 
		ll cyc = 0 ; 
		for(int j = 0 ;j < N ;j++){
			vis[j] = 0 ; 
		}
		vector<ll> vec ; 
		while(!vis[cur]){
			vec.push_back(b[cur]) ; 
			cyc += b[cur] ; 
			vis[cur] = 1; 
			cur = a[cur] ; 
		}
		ans = 0 ; 

		ll buckets = k / (int) vec.size() ; 

		if(cyc > 0){
			ans = buckets * cyc ;
		}

		ll rem = k % (vec.size()) ; 

		ll add = 0 , best = 0 ;
		for(int j = 0 ;j < rem ;j ++){	
			add+= vec[j] ; 
			best = max(best , add) ; 
		}
		ans+=best ; 

		if(buckets){
			ll add2 = 0 , best2 = 0 ; 
			ll rem = k % (vec.size()) + (int) vec.size() ; 
			for(int j = 0 ;j < rem ;j ++){
				add2+=vec[j%(int) vec.size()] ; 
				best2 = max(best2 , add2) ; 
			}
			ans = max(ans , max(0ll , (buckets -1 ) * cyc )  + best2  ) ; 
		}
		out = max(out , ans) ; 

	}

	cout<< out; 
	return 0 ; 
}
