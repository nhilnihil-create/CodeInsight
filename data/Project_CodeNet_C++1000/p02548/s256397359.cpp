#include<bits/stdc++.h>
#define ll  long long int
#define db long double 
#define ull unsigned long long int
// #define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
// #define INF 10000000000000
#define MOD 1000000007
#define MAXN 200005
 
using namespace std;

ll mod=998244353;
 
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}

const ll M=3000006;
ll f[M],inv[M];

void compute(){
    f[0]=1;
    rep(i,1,M-1){
        f[i]=(1LL*i*f[i-1])%mod;
    }
    inv[M-1]=expo(f[M-1],mod-2,mod);
    for(ll i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%mod;
    }
}
ll C(ll n,ll r){
    return (1LL*((1LL*f[n]*inv[r])%mod)*inv[n-r])%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // compute();
    int tests=1;
    // cin>>tests;    
    while(tests--)
    {
    	ll i,j,k,n;
    	cin>>n;
    	ll ans=0;
    	rep(i,1,sqrt(n))
    	{
    		j=i;
    		ll cur=0;
    		while(i*j<n)
    		{
    			j++;
    			cur+=2;
    		}
    		cur--;
    		ans+=max(0LL,cur);
    	}

    	cout<<ans;

    }

    return 0;
}
    