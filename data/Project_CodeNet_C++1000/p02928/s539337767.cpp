#include <bits/stdc++.h>

#define f(i,a,b) for( ll  i = a; i < (ll) b ; i++ ) 
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
#define inter   ios::sync_with_stdio(false);cin.tie(0)

// policy-based



using namespace std;


typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;



 
const ll MAX = 1e5 + 100;
const ll inf = 1e9;
const ll mod = 1e9+7;

ll a[MAX],c[MAX];
ll mul(ll x,ll y){
	return (x*y)%mod;
}
int main(){
	fastio;
	ll n,k,ans = 0;
	cin >> n >> k;
	f(i,0,n) cin >> a[i], c[a[i]]++;
	f(i,0,n){
		f(j,i+1,n){
			if(a[i] > a[j]) ans++;
		}
	}
	ans *= k;
	ll cant = n;
	af(i,2000,1){
		cant -= c[i];
	 
		ans +=   mul( mul(  ((k*(k-1)) /2)%mod , cant),c[i] )  ; 
		ans = ans%mod;
	}
	cout << ans << endl;
}