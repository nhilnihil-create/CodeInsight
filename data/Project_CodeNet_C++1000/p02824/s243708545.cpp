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

int n,m,v,p;
vi a;
int thres;

bool det(int i){
    if (a[i] >= thres) return true;
    int maxi = a[i] + m;
    if (maxi < thres) return false;
    int waste = (p-1 + n-i-1 + 1) * m;
    
    int sat = 0;
    FOR(j,p-1,i){
        sat += maxi - a[j];
    }
    return waste + sat >= v * m;
}


signed main(){
    cin >> n >> m >> v >> p;
    a.resize(n);
    REP(i,n) cin >> a[i];

    sort(all(a), greater<int>());
    thres = a[p-1];

    int hi = n;
    int lo = p-1;
    while(hi-lo > 1){
        int mid = (hi+lo)/2;
        // cerr << mid << " " << det(mid) << endl;
        (det(mid) ? lo : hi) = mid;
    }
    cout << lo+1 << endl;
}