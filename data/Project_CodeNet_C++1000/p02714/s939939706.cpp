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


void solve(){
	ll r=0, g=0, b=0;
	ll n;
	string s;
	cin >> n >> s;
	f0(n){
		if(s[i] == 'R')r++;
		else if(s[i] == 'B')b++;
		else g++;
	}
	ll ans = 0;
	for(ll i = n-1; i >= 0; i--){
		set < char > st;
		st.in('R') , st.in('B') , st.in('G');
		if(s[i] == 'R')r--, st.erase(s[i]);
		else if(s[i] == 'B')b--,st.erase(s[i]);
		else g--,st.erase(s[i]);
		ll kr = r , kg = g , kb = b;
		for(ll j = i-1; j >= 0; j--){
			ll k = i-j;
			if(s[j] == 'R')kr--;
		    else if(s[j] == 'B')kb--;
		    else kg--;
		    if(s[i] == s[j]) continue;
		    st.erase(s[j]);
		    char bit = *st.begin();
			ll pw;
			if(bit == 'R')pw=kr;
		    else if(bit == 'B')pw=kb;
		    else pw=kg;
			if(j-k >= 0){
				if(s[j-k] == bit) ans += max(0ll, (pw-1)); 
				else ans += pw;
			}else ans += pw;
			st.in(s[j]);
			//if(i == n-1) cout << ans << '\n';
		}
		st.clear();
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
