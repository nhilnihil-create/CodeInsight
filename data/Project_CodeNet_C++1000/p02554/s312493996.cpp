 #include <bits/stdc++.h>
 
#define f(i,a,b) for( ll i = a; i < b ; i++ )
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ones(x) (ll) __builtin_popcount(x)
#define fs first
#define sc second
#define pb push_back
#define po pop_back
#define mp make_pair 
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tsie(nullptr);cout.tie(nullptr)
#define watch(x) cout << (#x) << " is " << (x) <<"\n"
#define PI 3.1415926535
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
const ll mod = 1e9+7;
const ll MAX = 1e5+10;
const ll inf = 1e18+7;

ll binpow(ll a,ll b){
	a%=mod;
	ll res= 1;
	while(b>0){
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res%mod;
}

int main(){
	fastio;
	ll n;
	cin>>n;
	ll ans = (binpow(10,n)- (2*binpow(9,n))%mod + mod)%mod;
	ans = (ans+binpow(8,n))%mod;
	cout<<ans<<"\n";
    return 0; 
}