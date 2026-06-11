//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("tune=native")
    #pragma GCC target ("avx")
    //----------------------------
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    #define int ll

    #define FOR(i,j,n) for (int i=(int)(j);i<(n);i++)
    #define REP(i,n) for (int i=0;i<(int)(n);i++)
    #define REPS(i,n) for (int i=1;i<=(int)(n);i++)
    #define REPN(i,n) for (int i=(int)(n)-1;i>=0;i--)
    #define REPNS(i,n) for (int i=(int)(n);i>0;i--)

    #define I(n) scanf("%lld", &(n))
    #define LL(n) scanf("%lld", &(n))
    #define pb(n) push_back((n))
    #define mp(i,j) make_pair((i),(j))
    #define eb(i,j) emplace_back((i),(j))
    #define y0 y3487465
    #define y1 y8687969
    #define j0 j1347829
    #define j1 j234892
    #define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() )

    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())

    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef vector<vpi> vvpi;
    typedef vector<vvi> vvvi;

    const int mod = 1000000007;

//--------------------------------------------

int n,k;
vi h;
int dp[302][302];
int f[302][302];

signed main(){
    I(n); I(k);
    h.resize(n+1);
    REP(i,n) I(h[i+1]);
    h.pb(0);
    REP(i,n+2) REP(j,n+2)
        f[i][j] = max(0LL, h[j]-h[i]);
    REP(i,302) REP(j,302) dp[i][j] = INT64_MAX / 2;
    dp[0][0] = 0;
    REP(i,n+1){
        REP(j,k+1){
            REPS(skip, k-j+1){
                if (i+skip > n+1) break;
                dp[i+skip][j+skip-1] = min(dp[i+skip][j+skip-1], dp[i][j] + f[i][i+skip]);
            }
        }
    }
    // REP(j,k+1) { REPS(i,n+1) cerr << dp[i][j] << " "; cerr << endl;}  

    int ret = INT64_MAX;
    REP(j,k+1) ret = min(ret, dp[n+1][j]);
    cout << ret << endl;
}