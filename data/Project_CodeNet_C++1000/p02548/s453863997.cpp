
// Problem : C - A x B + C
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*

WINNERS NEVER QUIT AND QUITTERS NEVER WIN!!

Falling down is an accident, Staying down is a choice.

*/

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
#define MAXN   1000001
  
// stores smallest prime factor for every number 
ll spf[MAXN];

void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

ll calc(ll x)
{
	map<ll,ll> m; 
    while (x != 1) 
    { 
        m[spf[x]]++; 
        x = x / spf[x]; 
    }
    ll ret=1;
    for(auto a:m)
    {
    	ret*=(a.S+1);
    }
    return ret;
}

ll n,ans=0;

int main()
{
    io;
    sieve();
    cin>>n;
    
    FOR(c,1,n)
    {
    	ans+=calc(n-c);
    }
    
    cout<<ans;
    
    return 0;
}

