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
vi a;

vi divs(int x){
    vi ret;
    for (int i = 1; i*i <= x; i++){
        if (x%i == 0){
            ret.pb(i);
            ret.pb(x/i);
        }
    }
    sort(all(ret));
    uniq(ret);
    return ret;
}
int xsort;
bool f(int x){
    auto ai = a;
    REP(i,n) ai[i] %= x;
    sort(all(ai));
    
    auto acump = ai;
    REP(i,n-1) acump[i+1] += acump[i];
    auto acumn = ai;
    REP(i,n) acumn[i] = x - acumn[i];
    REPN(i,n-1) acumn[i] += acumn[i+1];
    acumn.pb(0);

    int op = INT64_MAX;
    REP(i,n) op = min(op, max(acump[i] , acumn[i+1]));
    cerr << x << " " << op << endl;
    return op <= k;
}

signed main(){
    I(n); I(k);
    a.resize(n);
    REP(i,n) I(a[i]);
    int asum = accumulate(all(a), 0LL);
    // cerr << asum << endl;
    auto dv = divs(asum);
    int ok = 0;
    REP(i,sz(dv)) ok = f(dv[i]) ? i : ok;
    cout << dv[ok] << endl;
}
