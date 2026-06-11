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
typedef pair<ll ,ll> 			pll;
typedef pair<ld,ld> 			pld;
typedef unordered_map<ll,ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5+7;
const ll 	MAX7 	= 	1e+7+7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9+7;
const ll 	N 		= 	2*1e6;

vpll adj[MAXN];ll visit[MAXN]={};

// <------------- Declare Variables Here ------------> //

ll T=1;
unsigned long long n,x,y,m;
string s,t;
vll a;
// <------------- Implement Functions Here ----------> //

long long exponentiation(long long base, 
                        long long exp) 
{ 
    if (exp == 0) 
        return 1; 
  
    if (exp == 1) 
        return base % MOD; 
  
    long long t = exponentiation(base, exp / 2); 
    t = (t * t) % MOD; 
  
    // if exponent is even value 
    if (exp % 2 == 0) 
        return t; 
  
    // if exponent is odd value 
    else
        return ((base % MOD) * t) % MOD; 
} 

// <------------- Start of main() -------------------> //

void MAIN() {
	vll cnt0(60), cnt1(60);
	cin>>n;
	for(ll k=0;k<n;k++) {
		cin>>x;
		for(ll i=0;i<60;i++) {
			unsigned long long val = pow(2,i);
			if((x & val)) {
				cnt1[i]++;
			}
			else {
				cnt0[i]++;
			}
		}
	}


	ll ans = 0;
	for(ll i=0;i<60;i++) {
		ans += (exponentiation(2,i) * ((cnt0[i] * cnt1[i])%MOD))%MOD;
		//cout<<ans<<" ";
		ans%=MOD;
	}
	cout<<ans;
}

int main() {
	fastio;randomINT;
	//cin>>T;
	while(T--) {
		MAIN();
	}
	return 0;
}

