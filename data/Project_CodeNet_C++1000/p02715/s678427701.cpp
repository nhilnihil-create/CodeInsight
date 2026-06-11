#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef pair<ll , ll> lli;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;
typedef vector<lli> vlli;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define in insert
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(b) for(int i=1;i<=(b);i++)
#define f11(b) for(int j=1;j<=(b);j++)
#define f2(a,b) for(int i=(a);i<=(b);i++)
#define f22(a,b) for(int j=(a);j<=(b);j++)
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld", &a , &b)
#define pf(a) printf("%lld\n",a)
#define pff(a,b) printf("%lld %lld\n", a , b)
#define PI 3.14159265359
#define bug printf("**!\n")
#define mem(a , b) memset(a, b ,sizeof(a))
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)

const ll mod = (ll)1e9+7;
const ll maxn = (ll)2e5+5;
const int nnn = 1048590;
const int inf = numeric_limits<int>::max()-1;
//const ll INF = numeric_limits<ll>::max()-1;
const ll INF = 1e18;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

ll bm(ll a , ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans*a)%mod;
		a *= a;
		a %= mod;
		b /= 2;
	}
	return ans;
}

void solve(){
	ll n,k;
	cin >> n >> k;
	ll ans = 0;
	ll pre[k+5];
	mem(pre, 0);
	for(ll i = k; i >= 1; i--){
		ll res = (bm(k/i , n));
		ll res2 = 0;
		for(ll j = i; j <= k; j += i) res2 += pre[j] , res2 %= mod;
		ans += i*(res-res2 +mod)%mod;
		pre[i] = (res-res2+mod)%mod;
		ans %= mod;
		//cout << ans << '\n';
	}
	cout << ans;
	return;
}


int main() {
   
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll T;
    T=1;
   // cin >> T;
    //scanf("%lld",&T);
    ll CT = 0;
    //work();
    while(T--){
    	//cout << "Case " << ++CT <<": " ;
    	//printf("Case %lld: ",++CT);
		solve();
	}
    
    return 0;
}
