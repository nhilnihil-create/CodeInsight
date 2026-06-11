#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std ;
using namespace atcoder ;
using ll = long long ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using pll = pair<ll,ll> ;
const int INF = 1e9 ;
void chmin(int &a,int b){if(a>b) a = b ;}
void chmax(ll &a,ll b){if(a<b) a = b ;}
void YorN(bool a){cout << (a?"YES":"NO") << "\n" ;}

int main(){
	int n,q ;
	cin >> n >> q ;
	fenwick_tree<ll> ft(n) ;
	for(int i=0;i<n;i++){
		ll a ; cin >> a ;
		ft.add(i,a) ;
	}
	while(q--){
		ll t,u,v ;
		cin >> t >> u >> v ;
		if(t) cout << ft.sum(u,v) << endl ;
		else ft.add(u,v) ;
	}
}