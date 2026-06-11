/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
const int MAXN = 1e6+6 ;
#define pb push_back 
#define X first 
#define Y second 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define pli pair<ll,int> 
#define pil pair<int,ll> 
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setprecision(10) ;
#define is(x) cout<<#x<<" : "<<x<<endl ;
// #define DEBUG
bool notPrime[MAXN] ;
ll sumz[MAXN];
vector<ll> primes ;
void sieve()
{
    f(i,2,MAXN)
    {
        if(notPrime[i]) continue ;
        primes.pb(i);
        for(ll j=(ll)i*i;j<MAXN;j+=i)
        {
            notPrime[(int)j] = true ;
        }
    }
}
void init()
{
    sumz[1] = 1 ;
    sumz[2] = 3 ;
    f(i,3,MAXN)
    {
        sumz[i] = sumz[i-1]+i ;
    }
}
int main()
{
    fio ;
    /* ======================Start of code ================ */
    ll N;cin>>N ;
    ll orig = N ;
    if(N==1) return cout<<0<<"\n",0 ;
    sieve() ;
    init() ;
    ll ans = 0 ;
    f(i,0,primes.size())
    {
        int k=0;
        ll p = primes[i] ;
        if(p>N ) break ;
        if(N%p) continue ;
        while((N%p)==0) N/=p,k++ ;
        #ifdef DEBUG 
        if(k) {is(p);is(k) ;}
        #endif 
        ans+=(ll)(upper_bound(sumz,sumz+MAXN,k)-sumz)-1 ;
    }
    cout<<(ans+(N!=1))<<"\n" ;
    /* ======================End of code ================== */
}