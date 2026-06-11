
// Problem : D - Div Game
// Contest : AtCoder - AtCoder Beginner Contest 169
// URL : https://atcoder.jp/contests/abc169/tasks/abc169_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef vector<long> vl;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;

#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define REV(i,a,b) for(long long i=a;i>=b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define tc ll tests;cin>>tests;while(tests--)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define coutv(v) for(auto it: (v))cout<<it<<" ";newl;
#define cout2d(v) for(auto it: (v)) {for(auto j:it) cout<<j<<" ";newl;}
#define cinv(v,n) vll (v)(n);FOR(i,0,(n)){cin>>v[i];}
#define cinvg(v,n) (v).resize(n);FOR(i,0,(n)){cin>>v[i];}
#define cin2d(v,n,m) vvll (v)(n,vll(m,0));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define cin2dg(v,n,m) (v).resize(n,vll(m));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define newl cout<<"\n"
#define mod 1000000007
#define INF LLONG_MAX/2

vll nums;

umll pf;
void pfact(ll n)
{
	while(n%2==0)
	{
		n/=2;
		pf[2]++;
	}
	for(ll i=3;i*i<=n;i+=2)
	{
		while(n%i==0)
		{
			n/=i;
			pf[i]++;
		}
	}
	if(n!=1)//when prime
	{
		pf[n]++;
	}
}

int main()
{
    io;
    
    FOR(i,1,50)
    {
    	nums.pb((i*(i+1))/2);
    }
    ll n,cnt=0;
    cin>>n;
    if(n==1){cout<<0;return 0;}
    pfact(n);
    
    for(auto x: pf)
    {
    	//cout<<x.F<<" "<<x.S;newl;
    	ll ind=ub(all(nums),x.S)-nums.begin();
    	cnt+=ind;
    }
    cout<<cnt;
    return 0;
}
