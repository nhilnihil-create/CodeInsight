#include<bits/stdc++.h>
using namespace std; 
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
 
typedef long long int ll; 
typedef long double ld; 

ll mod = 1e9+7;

ll add(ll a, ll b){
	a = a%mod;
	b = b%mod;
	return (mod+(a+b)%mod)%mod;
}

ll mul(ll a, ll b){
	a = a%mod;
	b = b%mod;
	return (mod+(a*b)%mod)%mod;
}

ll solve(ll node, vector<ll> vec[], vector<ll> &flg){
	flg[node] = 1;
	ll cnt = 1;
	for(ll i: vec[node]){
		if(flg[i]==0){
			cnt += solve(i, vec, flg);
		}
	}
	return cnt;
}

int main(){
	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m;
	cin>>n>>m;
	
	vector<ll> vec[n+1];
	vector<ll> flg(n+1, 0);
	
	for(ll i=0;i<m;i++){
		ll a, b;
		cin>>a>>b;
		a--;
		b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	ll ans = 0;
	for(ll i=0;i<n;i++){
		if(flg[i]==0){
			ans = max(ans,solve(i, vec, flg)); 
		}
	}
	cout<<ans<<endl;
}
