//#pragma optimization_level 3
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordset;
*/

#define fr first
#define sc second
#define vec vector
#define pb push_back
#define pii pair<int, int>
#define fo(x,y) for(int x = 1 ; x <= y ; ++x)
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;

typedef long long ll;
typedef unsigned int uint;
const int nmax = 200005;
const ll linf = LLONG_MAX;
const ll mod = 1e9+7;
const int inf = INT_MAX;

ll n, a, b;

ll pw(ll x , ll y){
	ll sq = x;
	ll ret = 1;
	for(ll k = 0 ; (1<<k) <= y ; k++){
		if((1<<k)&(y)){
			ret *= sq;
			ret %= mod;
		}
		sq *= sq;
		sq %= mod;
	}
	return ret;
}

ll co( ll x ){
	ll ret = n;
	for(int i = 2 ; i <= x ; i++){
		ret *= pw(i,mod-2);
		ret %= mod;
		ret *= (n-i+1);
		ret %= mod;
	}
	return ret;
	// n!/ (a)! (n-a)!
	// n!/ (a-1)! (n-a+1)!
}


int main(){
	cin >> n >> a >> b;
	// 2 ^ n - n choose a - n choose b
	cout << (pw(2,n) - co(a) - co(b) - 1 + 2*mod)%mod << '\n';
}
