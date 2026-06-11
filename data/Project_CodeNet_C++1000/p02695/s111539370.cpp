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

const ll mod = 1000000007;
const ll maxn = (ll)2e5+5;
const int nnn = 1048590;
const int inf = numeric_limits<int>::max()-1;
//const ll INF = numeric_limits<ll>::max()-1;
const ll INF = 1e18;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};
vector < ll > v;
ll q , a[55],b[55],c[55],d[55] , n,m, ans = 0;
void dp(ll pos, ll mx){
	if(pos ==  n){
		vector < ll > r = v;
		reverse(r.begin(),r.end());
		ll res= 0;
		//printf("%lld\n",r.size());
		f0(q){
			if(r[b[i]-1] - r[a[i]-1] == c[i]) res += d[i];
		}
		ans = max(res, ans);
		return;
	}
	for(ll i = mx; i >= 1; i--){
		v.pb(i);
		dp(pos+1 , i);
		v.pop_back();
	}
	return;
}

void solve(){
	cin >> n >> m >> q;
	f0(q) cin >> a[i] >> b[i] >> c[i] >> d[i];
	dp(0 , m);
	cout << ans;
	return;
}


int main() {
   
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll T;
    T=1;
    //cin >> T;
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
