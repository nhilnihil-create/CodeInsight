//#pragma optimization_level 3
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#include<string.h>
#define inf 1000000000000000000
#define maxn 200005
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
#define PI 3.14159265359
#define endl '\n'
#define mapint_iterator map<int,int> :: iterator
#define mapll_iterator map<ll,ll> :: iterator
#define setint_iterator set<int> :: iterator
#define setll_iterator set<ll> :: iterator
#define cps CLOCKS_PER_SEC
#define setpint_iterator set<pint> :: iterator
#define setpll_iterator set<pll> :: iterator
#define cout1(a) cout<<a<<endl
#define cout2(a,b) cout<<a<<' '<<b<<endl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<endl
#define print_double(i) printf("%.9llf\n",i)
typedef priority_queue<pair<pll,pll>,vector<pair<pll,pll> >,greater<pair<pll,pll> > > pqset;
typedef priority_queue<pll,vector<pll>,greater<pll> > pqset_ll;
#define pb push_back
#define pf push_front
#define fi first
#define mkp make_pair
#define se second
ll dxk[]={0,0,1,-1,1,1,-1,-1};
ll dyk[]={1,-1,0,0,1,-1,1,-1};
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> os_pair;
#define acc (ios::sync_with_stdio(false),cin.tie(0))
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(ll i=n;i>0;i--)
#define repeat(i,start,n) for(ll i=start;i<n;i++)
#define power2(i) ((ll)1<<(ll)i)
ll ll_max(ll a,ll b,ll c){return max(a,max(b,c));}
int int_max(int a,int b,int c){return max(a,max(b,c));}
ll ll_min(ll a,ll b,ll c){return min(a,min(b,c));}
int int_min(int a,int b,int c){return min(a,min(b,c));}
ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);} 
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
ll power(ll a,ll b){
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	ll res=1;
	if(b%2){
		res=(c*c);
		if(res>=mod)
			res%=mod;
		res*=a;
	}
	else
		res=((c*c));
	if(res>=mod)
		res%=mod;
	return res;
}
ll power(ll a,ll b,ll mod1){
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	ll c=power(a,b/2,mod1);
	ll res=1;
	if(b%2){
		res=(c*c);
		if(res>=mod1)
			res%=mod1;
		res*=a;
	}
	else
		res=((c*c));
	if(res>=mod1)
		res%=mod1;
	return res;
}
ll modInv(ll a){return power(a,mod-2);}
ll fact[1],inv[1];
void factorial(ll n){
	fact[0]=1;
	for(ll i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
		if(fact[i]>=mod)
			fact[i]%=mod;
	}
}
void InvFactorial(ll n){
	inv[0]=1;
	for(ll i=1;i<=n;i++)
		inv[i]=modInv(fact[i]);
}
ll ncr(ll n,ll r){
	if(n<r||n<0||r<0)
		return 0;
	ll b=inv[n-r];
	ll c=inv[r];
	ll a=fact[n]*b;
	if(a>=mod)
		a%=mod;
	a*=c;
	if(a>=mod)
		a%=mod;
	return a;
}
bool prime[1];
vector<int> primes;
void remove_duplicates(vector<int> &v){sort(v.begin(),v.end());int _size=unique(v.begin(),v.end())-v.begin();v.resize(_size);}
ll gcd(ll u, ll v){
    ll shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) {
            ll t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}
void sieve(ll n){
    memset(prime,true,sizeof(prime));
	prime[1]=false; 
    for (ll p=2;p*p<=n;p++){
        if (prime[p]){  
            for (ll i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
    repeat(i,2,n+1)
    	if(prime[i])
    		primes.pb(i);
}
//ifstream cin("b_read_on.txt"); ofstream cout("output.txt");
//Use (<<) for multiplication
//Use (>>) for division
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed;cerr.tie(NULL);
// find_by_order -> value at index
// order_of_key -> index of value
// while using (1<<i) use (1LL<<i) 
// in Floyd-Warshall Algo, k is outer loop 
// If an element was not initially in map and if asked mp[a],the element gets inserted 
// a%=mod take a lot of time... try to use it minimum...use if(a>=mod) a%=mod
//cout<<(double) can be harmful , always use printf(%.9llf)...take scanf("%lf",&p[i][j]) as input , not llf;
//use s.erase(it++) for erasing iterator and then moving to the next one
//never use adj.resize(n) as value is persistent, always erase
//use __builtin_popcountll() for ll
//__gcd(0,0) gives runtime error
//power(a,b) == power(a,b%phi(a)) Fermet's Theorem
//never use "=" operator in compare function
//For checking odd cycles, check bipartite
//Range in iterative segment tree [a,b)
// no of prime numbers in range : (70,19) , (1000,168) , (100000,1229) , (sqrt(10^9),3409) ;
ll dp[1000][(1<<12)];
vector<int> v[1000];
int maxx;
int n,m;
ll a[1000];
ll func(int i,int mask){
	if(i==m&&mask==maxx)
		return 0;
	if(i==m)
		return 10000000000;
	if(dp[i][mask]!=-1)
		return dp[i][mask];
	ll ans=func(i+1,mask);
	ll ans1=0;
	int mask1=mask;
	rep(j,v[i].size())
		mask1|=(1<<v[i][j]);
	ans=min(ans,func(i+1,mask1)+a[i]);
	return dp[i][mask]=ans;
}
void solve(int countu){
	cin>>n>>m;
	maxx=(1<<n)-1;
	int check[n]={0};
	rep(i,m){
		int b;
		cin>>a[i]>>b;
		rep(j,b){
			int c;
			cin>>c;
			c--;
			v[i].pb(c);
			check[c]=1;
		}
	}
	rep(i,n){
		if(check[i]==0){
			cout1(-1);
			return;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout1(func(0,0));
}
int main(){
	cin.tie(NULL);cout.tie(NULL);cin.sync_with_stdio(0);cout.sync_with_stdio(0);cout<<fixed;
	srand(time(0));
	//cout.precision(9);
	int t=1;
	//cin>>t;
	int countu=1;
    for(int i=1;i<=t;i++){
    	solve(countu);
    	countu++;
    }
}