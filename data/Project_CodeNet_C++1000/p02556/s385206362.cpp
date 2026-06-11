
// Problem : E - Dist Max
// Contest : AtCoder - AtCoder Beginner Contest 178
// URL : https://atcoder.jp/contests/abc178/tasks/abc178_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<ll> 
#define all(x) (x).begin() , (x).end()
#define inf 10000000000000000
#define mod 1000000007

void dbg(){
	cerr << endl;
}
template<typename Head , typename... Tail>
void dbg(Head h , Tail... t){
	cerr << h << " ";
	dbg(t...);
}

#ifdef EMBI_DEBUG
#define debug(...) cerr << "(" << #__VA_ARGS__  << "): ", dbg(__VA_ARGS__)
#else 
#define debug(...)
#endif

const ll max_n = 1e5 + 9;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
void solve(){
	ll n;
	cin >> n;
	
	ll x[n] , y[n];
	
	for(ll i = 0 ; i < n ; i++){
		cin >> x[i] >> y[i];
	}
	ll sum[n] , diff[n];
	
	for(ll i = 0 ; i < n ; i++){
		sum[i] = x[i] + y[i];
		diff[i] = x[i] - y[i];
	}
	
	
	ll max1 = -inf;
	
	ll min_sum = inf , min_diff = inf , max_sum = -inf , max_diff = -inf;
	for(ll i = 0 ; i < n ; i++){
		max1 = max(max1 , sum[i] - min_sum);
		max1 = max(max1 , diff[i] - min_diff);
		
		max1 = max(max1 , max_sum - sum[i]);
		max1 = max(max1 , max_diff - diff[i]);
		
		min_sum = min(min_sum , sum[i]);
		min_diff = min(min_diff , diff[i]);
		max_sum = max(max_sum , sum[i]);
		max_diff = max(max_diff , diff[i]);
	}
	
	cout << max1 << "\n";
}
signed main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}