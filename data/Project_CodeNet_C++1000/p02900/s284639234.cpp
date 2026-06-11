
#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define DISP1(as)		for(auto it : as) cout<<it.f<<" "<<it.s<<") ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	2e+5 + 99;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, k, l, q, x, y, m;
string s, t;

ll rem;
ll cnt[3];


// < ----------- func eh ---------------- ? //

bool isprime(ll n) {
	if(n == 1) return true;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) return false;
	}
	return true;
}


vll factors(ll n) {
	vll f;
	for(ll i=1;i*i<=n;i++) {
		if(n%i==0) {
			f.pb(i);
			if(i*i != n) f.pb(n/i);
		}
	}

	sort(all(f));
	return f;
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n >> m ;
	ll val = __gcd(n,m);

	vll f = factors(val);
	ll cnt = 1;

	for(ll i=1;i<f.size();i++) if(isprime(f[i])) cnt++;

	cout<<cnt;
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}