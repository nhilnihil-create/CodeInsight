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

int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, m, x, y, q, k;
string s[2005], t;

// <------------- Implement Functions Here ----------> //

ll l[4000][4000];
ll r[4000][4000];
ll u[4000][4000];
ll d[4000][4000];

// <------------- Start of main() -------------------> //

void MAIN() {
	cin>>n>>m;
	for(ll i=1;i<=n;i++) {
		cin>>s[i];
		s[i] = '#' + s[i];
		for(ll j=1;j<=m;j++) {
			l[i][j] = u[i][j] = d[i][j] = r[i][j] = (s[i][j] == '.');
		}
	}

	for(ll i=2;i<=n;i++) {
		for(ll j=1;j<=m;j++) {
			if(u[i][j]) {
				u[i][j] += u[i-1][j];
			}
		}
	}

	for(ll i=n-1;i>=1;i--) {
		for(ll j=1;j<=m;j++) {
			if(d[i][j]) {
				d[i][j] += d[i+1][j];
			}
		}
	}

	for(ll i=1;i<=n;i++) {
		for(ll j=2;j<=m;j++) {
			if(l[i][j]) {
				l[i][j] += l[i][j-1];
			}
		}
	}

	for(ll i=1;i<=n;i++) {
		for(ll j=m-1;j>=1;j--) {
			if(r[i][j]) {
				r[i][j] += r[i][j+1];
			}
		}
	}

	ll maxi = 0;

	for(ll i=1;i<=n;i++) {
		for(ll j=1;j<=m;j++) {
			if(s[i][j]=='.')
				maxi = max(maxi,u[i-1][j] + d[i+1][j] + l[i][j-1] + r[i][j+1] + 1);
		}
	}

	cout<<maxi;
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}
