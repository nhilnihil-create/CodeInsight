#include<bits/stdc++.h>
#define ll long long
#define db double
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
using namespace std;

 ll mod=1e9 +7;
const ll M=500006;
ll f[M],inv[M];
ll expo(ll base,ll exponent){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
    f[0]=1;
    rep(i,1,M-1){
        f[i]=(1LL*i*f[i-1])%mod;
    }
    inv[M-1]=expo(f[M-1],mod-2);
    for(ll i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%mod;
    }
}
ll C(ll n,ll r){
    return (1LL*((1LL*f[n]*inv[r])%mod)*inv[n-r])%mod;
}

vector<bool>  prime(1000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=1000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=1000001; i += p) 
                prime[i] = false; 
        } 
    } 
}

bool check(string s,char c)
{
	for(auto x:s)
	{
		if(x==c) return true;
	}
	return false;
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
 //    #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // compute();
    ll tests=1;
   // cin>>tests;
    while(tests--)
    {
    	ll n,m,i,j;
    	cin>>n>>m;
    	vector<ll>h(n+1);
    	for(i=1;i<=n;i++) cin>>h[i];
    	vector<ll> graph[n+1];
    	for(i=0;i<m;i++)
    	{
    		ll a,b;
    		cin>>a>>b;
    		graph[a].pb(b);
    		graph[b].pb(a);
    	}
    	ll ans=0;
    	for(i=1;i<n+1;i++)
    	{
    		ll mx=0;
    		for(auto x:graph[i])
    		{
    			mx=max(mx,h[x]);
    		}
    		if(mx<h[i]) ans++;
    	}
    	cout<<ans;
    }

	return 0;
}