#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,ll>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int N,K;
    Scd2(N,K);
    if( N==K ) {
        printf ("%d\n", 0);
        return 0;
    }
    vi h(N);
    Rep(i,N) Scd(h[i]);

    vector<map<int,ll>> dp(K+1);
    map<int,ll> dpki;
    map<int,ll> dpkip1;
    dp[0][1] = 1;

    Rep(ni,N){
        RRep(ki,K+1){
            for( pii mi : dp[ki] ){
                int hi = mi.first;
                ll dphi = mi.second;
                // printf ("!dp[%lld][%d] = %lld\n", ki, mi.first, mi.second );
                // hi to hhi
                // dp[ki][hi] -> dp[ki+1][hhi];
                // hhi = hi (消費)
                if( ki != K ){
                    if( dpkip1.find(hi) == dpkip1.end() ) dpkip1[hi] = 1e18;
                    dpkip1[hi] = min( dpkip1[hi], dphi );
                }
                // hhi = hi[ni] (温存)
                if( dpki.find(h[ni]) == dpki.end() ) dpki[h[ni]] = 1e18;
                dpki[h[ni]] = min( dpki[h[ni]], dphi+max(0,h[ni]-hi) );
            }
            dp[ki].clear();
            for( pii mi : dpki ){
                // printf ("?dp[%lld][%d] = %lld\n", ki, mi.first, mi.second );
                dp[ki][mi.first] = mi.second;
            }
            if( ki != K ) for( pii mi : dpkip1 ){
                // printf ("?dp[%lld][%d] = %lld\n", ki+1, mi.first, mi.second );
                if( dp[ki+1].find(mi.first) == dp[ki+1].end() ) dp[ki+1][mi.first] = 1e18;
                dp[ki+1][mi.first] = min( dp[ki+1][mi.first], mi.second);
            }
            dpkip1.clear();
            dpki.clear();
        }
            // printf (" \n");
    }

    ll ans = 1e18;
    Rep(ki,K+1){
        for( pii mi : dp[ki] ){
            // printf ("dp[%lld][%d] = %lld\n", ki, mi.first, mi.second );
            if( mi.second == 0 ) continue;
            ans = min( ans, mi.second );
        }
    }

    printf ("%lld\n", ans );

    return 0;
}


