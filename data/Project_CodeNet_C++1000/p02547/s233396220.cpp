// i_m_arin

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef priority_queue<ll> pqll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef map<ll,ll> mpll;
typedef set<ll> stll;

#define f(i, a, n) 	for(ll i=a; i<(ll)n; i++)
#define f2(i, a, b) for(ll i=a; i<=(ll)b; i++)
#define pb 			push_back
#define ff 			first
#define ss 			second
#define pf			push_front
#define mp			make_pair
#define all(a)		(a).begin(),(a).end()
#define decimal(x)	fixed<<setprecision(x)
#define fsort(a)	sort(all(a))
#define rsort(a)	sort(all(a),greater<>())
#define fast_io		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem0(a)		memset(a,0,sizeof(a))
#define mem1(a)		memset(a,-1,sizeof(a))
#define lcm(a,b)	(a*b)/__gcd(a,b)
#define ub(v,x)		upper_bound(all(v),x)-v.begin()
#define lb(v,x)		lower_bound(all(v),x)-v.begin()

const ld PI  = acos(-1);
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const ll SIZE= 100000;


void solve(){

ll n;
cin>>n;

vpll vp;
f(i,0,n){
	ll x,y;
	cin>>x>>y;
	vp.pb({x,y});
}
f(i,2,n){
	if(vp[i-2].ff==vp[i-2].ss && vp[i-1].ff==vp[i-1].ss && vp[i].ff==vp[i].ss){
		cout<<"Yes"<<endl;
		return;
	}
}
cout<<"No"<<endl;

}


int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}