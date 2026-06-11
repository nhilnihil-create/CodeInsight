#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define db double
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
using namespace std;
 
 ll mod=1e9 +7;
 
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
 
vector<bool>  prime(90000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=90000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=90000001; i += p) 
                prime[i] = false; 
        } 
    } 
}

const ll M=200006;
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

ll func(ll tot,ll given)
{
  ll res=0;
  for(ll i=0;i<=30;i++)
  {
    if((1<<i) & tot)
    {
      if(!((1<<i) & given))
      {
        res+=expo(2,i,mod);
      }
    }
    else
    {
      if((1<<i) & given)
        res+=expo(2,i,mod);
    }
  }
  return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // compute();
    // Sieve();
    ll tests=1;
    // cin>>tests;
    while(tests--)
    {
      ll i,j,n,tot=0;
      cin>>n;
      vector<ll>a(n),ans(n);
      rep(i,0,n-1)
      {
        cin>>a[i];
        tot^=a[i];
      }

      rep(i,0,n-1)
      {
        cout<<func(tot,a[i])<<" ";
      }


    }
    return 0;
   }