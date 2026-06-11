#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;


//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


struct Edge {
    int to, from;
    ll cost;
    Edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}
};

typedef vector<vector<Edge>> AdjList;
AdjList graph;

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec((int)B[0].size()));
    for(int i=0; i<A.size(); ++i){
        for(int k=0; k<B.size(); ++k){
            for(int j=0; j<B[0].size(); ++j){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] %MOD) % MOD;
            }
        }
    }
    return C;
}
mat mat_pow(mat A, ll n) {
    mat B(A.size(), vec((int)A.size()));

    for(int i=0; i<A.size(); ++i){
        B[i][i] = 1;
    }

    while(n > 0) {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}



int main() {
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N; cin >> N;
    vector<pii> vp;
    REP(i, N){
        int x, y; cin >> x>> y;
        vp.PB({x, y});
    }

    sort(all(vp), [](const pii& a, const pii& b) {
        return atan2(a.second, a.first) < atan2(b.second, b.first);
    });
    double ans = 0;
    for(int i=0; i<N; ++i){
        double xx=0, yy=0;
        for(int j=0; j<N; ++j){
            xx += vp[(i+j)%N].first;
            yy += vp[(i+j)%N].second;
            ans = max(ans, sqrt(xx*xx+ yy*yy));
        }
    }

    
    cout << ans << endl;
    return 0;

}