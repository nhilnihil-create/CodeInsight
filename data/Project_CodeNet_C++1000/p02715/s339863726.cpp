/*
********************
Author : Sahil Kundu
********************
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define pb(i) push_back(i)
#define f first
#define s second
#define mk(l,r) make_pair(l,r)
#define all(vc) vc.begin(),vc.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ms(i,j) memset(i,j,sizeof i)
#define w(t) while(t--)
#define len(s) s.length()
const ll MAX=1e5+5;
const ll INF=2e18+10;
const int inf=1e9+10;
bool isprime[MAX];
vector<ll> primes;
void allprimes()
{
    ms(isprime,true);
    isprime[1]=false;
    for(ll i=2;i*i<=MAX;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=MAX;j+=i)
                isprime[j]=false;
        }
    }
    for(ll i=2;i<=MAX;i++)
        if(isprime[i])
        primes.pb(i);
}
ll power(ll a,ll b)
{
    if(!b)return 1;
    ll res=power(a,b/2)%mod;
    res=res*res%mod;
    return (b%2 ? res*a : res)%mod;
}
void solve()
{
    allprimes();
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    ll dp[k+1];
    ms(dp,0);
    for(int i=k;i>=1;i--)
    {
        ll cal=k/i;cal=power(cal,n);
        for(int j=2*i;j<=k;j+=i)
        {
            cal=(cal-dp[j]+mod)%mod;
        }
        dp[i]=cal;
        cal=(cal*i)%mod;
        ans=(ans+cal)%mod;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    w(t) solve();
    return 0;
}