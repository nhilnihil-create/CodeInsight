//bismillahir rahmanir rahim            //Author:Fayed Anik
 
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define         ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define         ll                          long  long
#define         lf                          double
#define         pb(x)                       push_back(x)
#define         ull                         unsigned long long
#define         sfl(a)                      scanf("%lld",&a)
#define         sf(a)                       scanf("%d",&a)
#define         pf(a)                       printf("%d\n",a)
#define         pfl(a)                      printf("%lld\n",a)
#define         FOR(x,n)                    for(ll x=1;x<=n;++x)
#define         pii                         pair< ll , ll >
#define         mp(a,b)                     make_pair(a,b)
#define         UNIQUE(v)                   v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define         mod                         1000000007
#define         INF                         2e18
#define         EPS                         1e-15
#define         f1                          first
#define         f2                          second
#define         all(v)                      v.begin(),v.end()
#define         PI                          acos(-1)
#define         printminusone               printf("-1\n")
#define         bug                         printf("bug")
#define         FILEIN                      freopen("in.txt","r",stdin)
#define         FILEOUT                     freopen("out.txt","w",stdout)
 
//ll SET(ll mask,ll pos){ return mask = (mask | (1ll<<pos)); }
//ll RESET(ll mask,ll pos){ return mask = mask & ~(1ll<<pos); }
//bool CHECK(ll mask,ll pos) { return (bool) (mask & (1ll<<pos)); }
//priority_queue <ll, vector<ll>, greater<ll> > pq;
//int dx[]={0,0,1,-1,1,1,-1,-1};
//int dy[]={1,-1,0,0,1,-1,1,-1};

#define lim 1000005

ll fastexpo(ll b,ll p){
    ll res = 1;
    while( p ){
        if ( p&1 ){
            res = (res*b)%mod;
        }
        p = p>>1LL;
        b = ( b*b )%mod;
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,ans,tmp;
    sfl(n);
    if( n==1 ){
        printf("0\n");
        return 0;
    }
    ans = fastexpo(10,n);
    ans = (ans - ((2*fastexpo(9,n))%mod)+mod)%mod;
    ans = (ans+fastexpo(8,n))%mod;
    pfl(ans);
    return 0;
}