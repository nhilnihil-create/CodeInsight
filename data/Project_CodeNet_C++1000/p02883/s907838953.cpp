#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inter ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

// policy-based
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;	


using namespace std;


typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;

/*
typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/
 
const ll MAX = 1e6+100;
const ll inf = 1e15;
const ll mod = 1e9+7;


ll a[MAX],b[MAX],n,k;


bool go(ll x){
	vi num;
	ll ans = 0;
	f(i,0,n) ans+= max(0LL,a[i]- x/b[i] );
	return ans<=k;
}


int main(){
	fastio;
	cin >> n >> k;
	f(i,0,n) cin >> a[i];
	f(i,0,n) cin >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	reverse(b,b+n);
	ll ini = 0,fin = 1e12;
	while(ini< fin){
		ll mid = (ini+fin)/2;
		if(go(mid)) fin = mid;
		else ini = mid+1;
	}
	cout << ini << endl;
}