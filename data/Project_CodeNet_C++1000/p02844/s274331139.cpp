#ifndef COMPETITIVE_HEADER
    #pragma GCC optimize ("Ofast")
    #ifdef ONLINE_JUDGE
        #pragma GCC target ("avx512f")
    #else
        #pragma GCC target ("avx")
    #endif
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
#endif

int n;
string s;
bool left_have[10][30000], right_have[10][30000];
set<int> ans;

signed main(){
    cin >> n;
    cin >> s;
    REP(i,n){
        int c = s[i] - '0';
        if (!left_have[c][i]) FOR(j,i+1,n) left_have[c][j] = 1;
    }
    REPN(i,n){
        int c = s[i] - '0';
        if (!right_have[c][i]) REP(j,i) right_have[c][j] = 1;
    }
    REP(i,n){
        int c = s[i] - '0';
        REP(l,10) REP(r,10) 
            if (left_have[l][i] && right_have[r][i]) 
                ans.insert(l*100+c*10+r);
    }
    // for(auto p : ans) cerr << p << ", "; cerr << endl;
    cout << sz(ans) << endl;
}