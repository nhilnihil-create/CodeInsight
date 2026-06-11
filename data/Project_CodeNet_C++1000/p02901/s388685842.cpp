#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef int Int;
typedef pair<Int, Int> pii;
typedef pair<Int, double> pid;
typedef pair<double, double> pdd;
typedef pair<Int, pii> pip;
typedef pair<pii, Int> ppi;
typedef pair<double, Int> pdp;
typedef vector<Int> veci;
typedef vector<double> vecd;
typedef vector<int> veci;
typedef vector<ll> vecll;
typedef vector<double> vecd;
typedef vector<pii> vecpii;
typedef vector<ppi> vecppi;
typedef vector<veci> mati;
typedef vector<vecll> matll;
typedef vector<vecd> matd;
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (x).size()
#define CLR(x) memset(x,0,sizeof x)
#define pdebug() printf("%d\n",__LINE__)
#define REP(i, a, b) for(int i = (a);i <= (b);i++)
#define FORO(i, n) REP(i,0,(int)n-1)
#define FORI(i, n) REP(i,1,(int)n)
#define FORIT(i, t) for(auto i = t.begin();i != t.end();i++)
#define eps 1e-6
#define sqr(x) ((x)*(x))
#define dist(_a, _b) sqrt(sqr(_a.A-_b.A)+sqr(_a.B-_b.B))
#define norm(_a) sqrt(sqr(_a.A)+sqr(_a.B))
#define DEBUG 1
#if DEBUG
#define DUMP(a) do { std::cout << #a " = " << (a) << ", "; } while(false)
#define DUMPLN(a) do { std::cout << #a " = " << (a) << std::endl; } while(false)
#else
#define DUMP(a)
#define DUMPLN(a)
#endif
template<typename T, typename U>
inline void getMin(T &a, U b) { if (a > b) a = b; }
template<typename T, typename U>
inline void getMax(T &a, U b) { if (a < b) a = b; }
template<typename T>
vector<T> getVector(const int n) { return vector<T>(n); }
template<typename T>
vector<T> getVector(const int n, const T a) { return vector<T>(n, a); }
template<typename T>
vector<T> getEmptyVector() { return vector<T>(); }
template<typename T>
void appendAll(vector<T> &a, vector<T> b) { a.insert(a.end(), b.begin(), b.end()); }
// #define X first
// #define Y second
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const ll MOD = 1000000007;
const int MAXN = 1 << 17;
const int inf = 1 << 27;
const ll llinf = 1LL << 50;
const int NIL = -inf;
int popcount(int x) { return __builtin_popcount(x); }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    veci a(M), C(M);
    FORO(i, M) {
        cin >> a[i];
        int b; cin >> b;
        while(b--) {
            int c; cin >> c; c--;
            C[i] |= 1<<c;
        }
    }

    mati dp(M + 1, veci(1<<N, inf));
    dp[0][0] = 0;
    int ans = inf;
    FORO(i, M) {
        for(unsigned s = 0;s < (1<<N);s++) {
            if(dp[i][s] >= inf) continue;
            getMin(dp[i + 1][s], dp[i][s]);
            getMin(dp[i + 1][s | C[i]], dp[i][s] + a[i]);
        }
        getMin(ans, dp[i + 1][(1<<N) - 1]);
    }
    if(ans >= inf) ans = -1;

    cout << ans << endl;

    return 0;
}