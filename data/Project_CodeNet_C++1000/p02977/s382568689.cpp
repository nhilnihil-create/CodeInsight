#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,int>;
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
#define Repe(x,y,z) for(int x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(int x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
#define SpaceNewLine(a) Rep(i,a.size())cout<<a[i]<<(i==a.size()-1?'\n':' ')
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {
    // setup {{{ 1
    cin.tie(0);
    ios::sync_with_stdio(false);
    // }}}

    int N;
    Scd(N);

    bool ans = 1;

    int cnt = 0;

    int tn = N;
    while( tn ) { if( tn&1 ) cnt++; tn >>=1; }

    if( cnt == 1 ) ans = false;

    YesNo(ans);

    if( ans ){
        int NN = N;
        if( N % 2 == 0 ){
            int n = 0x10000000;
            while( (n & N) == 0 ) n >>= 1;
            printf ("%d %d\n", N, N-n+1);
            printf ("%d %d\n", N+N, N+n);
            NN--;
        }
        while( NN > 1 ){
            printf("%d %d\n", NN-1, NN );
            printf("%d %d\n", NN, 1 );
            printf("%d %d\n", 1, NN-1+N );
            printf("%d %d\n", NN-1+N, NN+N );
            NN -= 2;
        }
        printf ("%d %d\n", N+1,2 );
    }

    return 0;
}

