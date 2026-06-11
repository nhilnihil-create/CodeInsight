#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define maxn 300005

int n ;
int Xor[maxn] , val[maxn] ;
vector < pair<int,int> > vp ;
vector <int> g[maxn] ;

int dp[55][55] ;

void dfs(int u, int par , int x )
{
  //  printf("----%d %d\n",u,x) ;
    Xor[x] = u ;
    val[u] = x ;
    for(int i=0 ; i<g[u].size() ; i++)
    {
        int v = g[u][i] ;
        if(v==par) continue ;
        if( v <= n ) dfs(v,u,v^x) ;
        else dfs(v,u,(v-n)^x) ;
    }
}

int main()
{
    scanf("%d",&n) ;

    for(int i=0 ; i<=20 ; i++)
    {
        if( (n^(1<<i)) == 0 )
        {
            printf("No\n") ;
            return 0 ;
        }
    }

    int l = 0 , tot = 3 ;

    deque<int> dq ;

    for(int i=1 ; i<=3 ; i++) dq.push_back(i) ;
    for(int i=1 ; i<=3 ; i++) dq.push_back(i+n) ;

    for(l=2 ; (1<<l)+tot <= n ; l++ ){

        for(int j=1 ; j<=(1<<l) ; j++ ) dq.push_back(j+tot+n) ;
        for(int j=(1<<l) ; j>=1 ; j-- ) dq.push_front(j+tot ) ;

        tot += (1<<l) ;
    }

    for(int i=1 ; i<dq.size() ; i++) vp.pb( mp(dq[i-1],dq[i]) ) ;

    int rem =  n - tot ;

    int x = 0 ;

    for(int i=n+1 ; i<=tot+(1<<l) ; i++) x ^= i ;

    x &= ( (1<<l) - 1 ) ;

    dq.clear() ;

    if( rem%2==0 || x==0 )
    {
        for(int i = tot+1 ; i<n ; i++)
        {
            vp.pb( mp( i,i+1 ) ) ;
            vp.pb( mp( n+i,n+i+1 ) ) ;
        }

        if(x!=0) vp.pb( mp( tot+1 , x ) ) ;
        if(x!=0) vp.pb( mp( 2*n , x+n ) ) ;
    }
    else{

        for(int i = tot+2 ; i<n ; i++)
        {
            vp.pb( mp( i,i+1 ) ) ;
            vp.pb( mp( n+i,n+i+1 ) ) ;
        }

        vp.pb( mp( tot+2 , x ) ) ;
        vp.pb( mp( 2*n , x+n ) ) ;

        vp.pb( mp(tot+2,tot+1) ) ;

        for(int i=0 ; i<vp.size() ; i++)
        {
            g[ vp[i].xx ].pb( vp[i].yy ) ;
            g[ vp[i].yy ].pb( vp[i].xx ) ;
        }

        dfs( tot+1 , 0 , 0 ) ;

    //    printf("--%d %d %d\n" , Xor[ tot+1 ] , tot+n+1 , val[ Xor[ tot+1 ] ] ) ;
        vp.pb( mp( Xor[tot+1] , tot+1+n ) ) ;
     /*   g[Xor[tot+1]].pb( tot+1+n ) ;
        g[tot+1+n].pb( Xor[tot+1] ) ;


        for(int i=1 ; i<=n ; i++)
        {
            dfs(i,0,i) ;
            printf("%d: %d\n" ,i,(val[i+n]) ) ;
        } */
    }

    if(x==0 && tot < n )
    {
        vp.pb( mp( 2*n , 1 ) ) ;
        vp.pb( mp(n,tot+1+n) ) ;
    }

/*
    for(int i=0 ; i<vp.size() ; i++)
    {
        g[ vp[i].xx ].pb( vp[i].yy ) ;
        g[ vp[i].yy ].pb( vp[i].xx ) ;
    }
    for(int i=1 ; i<=n ; i++)
    {
        dfs(i,0,i) ;
        printf("%d: %d\n" ,i,(val[i+n]) ) ;
    }

    printf("%d\n",(int)vp.size()) ; */

    printf("Yes\n") ;
    for(int i=0 ; i<vp.size() ; i++) printf("%d %d\n",vp[i].xx,vp[i].yy) ;

    return 0 ;
}
