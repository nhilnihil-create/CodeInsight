// KNOW NOTHING!
#include <bits/stdc++.h>
#define ll long long int
#define F(i,j,k,in) for(ll i=j;i<k;i+=in)
#define DF(i,j,k,in) for(int i=j;i>=k;i-=in)
#define feach(it,l) for (auto it = l.begin(); it != l.end(); ++it)
#define fall(a) a.begin(),a.end()
#define sz(x) (int)x.size()
#define szs(x) (int)s.length()
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define eq equal_range
#define fs first
#define ss second
#define ins insert
#define mkp make_pair
#define endl "\n"
using namespace std;
typedef vector<ll> vll;
typedef vector<int> vin;
typedef vector<char> vch;
typedef vector<string> vst;
typedef set<ll> sll;
typedef set<int> sint;
typedef set<char> sch;
typedef set<string> sst;
typedef queue<ll> qll;
typedef queue<int> qin;
typedef deque<ll> dqll;
typedef deque<int> dqint;
typedef priority_queue<ll> pqll;
typedef priority_queue<int> pqin;
typedef map<ll,ll> mpll;
typedef map<int,int> mpin;
typedef pair<ll,ll> pll;
typedef pair<int,int> pin;
const ll MOD=1000000007;
const long double PI=3.1415926535897932384626433832795;
ll pwr(ll b,ll p){ll res=1;while(p){if(p&1) {res*=b; p--;}else{b*=b; p>>=1;}}return res;}
const int maxn = 1e7+1;
ll spf [maxn] , n; 
ll divi[maxn] ;
void seive () {
	for (ll i=2; i<=n; ++i) {
		if (!spf[i]) {
		spf[i]=i;
		for (ll j=i*i; j<=n;j+=i) {
			if (!spf[j]) spf[j]=i;
		}
	}
	}
}

void divisor () {
	divi[1]=1;
	F (j,2,n+1,1) {
	ll num = j ;
	ll res=1;
	while (num!=1) {
	ll cnt=0 , a=spf[num];
	while (num%a==0) {
		num=num/a;
		++cnt;
	}
	res*=(cnt+1);
}
divi [j] = res;
}
}
int main()
{
/*
freopen ("input.txt","r","stdin");
freopen ("output.txt","w","stdout");
*/
ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);
cin>>n;
ll ans=0;
seive ();
divisor ();
F (i,1,n+1,1) {
	ans+= (i*divi[i]);
}
cout<<ans;
return 0;
}
/* What we know is a drop , but what we don't know is an ocean !*/