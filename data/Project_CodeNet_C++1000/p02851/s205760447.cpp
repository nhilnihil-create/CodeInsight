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
vi acum;

signed main(){
    I(n); I(k);
    acum.resize(n);
    REP(i,n) {
        I(acum[i]);
        acum[i]--;
        acum[i] %= k;
    }
    map<int, vi> rem;
    rem[0].pb(-1);
    rem[acum[0]].pb(0);
    REP(i,n-1) {
        acum[i+1] = (acum[i] + acum[i+1]) % k;
        rem[acum[i+1]].pb(i+1);
    }
    REP(i,n) cerr << acum[i] << " "; cerr << endl;
    int ret = 0;
    for(auto p: rem){
        auto tgt = p.second;
        
        int lent = sz(tgt);
        REP(i,lent){
            int iplus = lower_bound(all(tgt), tgt[i] + k) - tgt.begin() - i - 1;
            // cerr << tgt[i] << ": " << iplus << endl;
            ret += iplus;
        }
    }
    cout << ret << endl;
}
