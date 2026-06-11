#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
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

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;
const ll  N  = 1000000007 ;// prime modulo value

int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, m, k, p, d;
ll x;
ll A, B;
string s;

// <------------- Implement Functions Here ----------> //

vll factor(ll n) {
	vll f;
	for(ll i=1;i*i <= n;i++) {
		if(n%i==0)
			f.pb(i);
	}
	return f;
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin>>m>>d;
	ll cnt = 0;
	for(ll i=2;i<=min(81ll,m);i++) {
		vll f = factor(i);
		for(ll j=0;j<f.size();j++) {
			if(f[j] < 10 && f[j] > 1 && i/f[j] < 10 && i/f[j] > 1) {
				if(f[j]*10 + i/f[j] <= d)
					cnt++;
				if(i/f[j] * 10 + f[j] <= d && f[j]!=i/f[j])
					cnt++;
			}
		}
	}
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
