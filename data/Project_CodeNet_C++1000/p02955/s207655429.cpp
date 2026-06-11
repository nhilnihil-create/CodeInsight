#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef int Int;
typedef pair<Int,Int> pii;
typedef pair<Int,double> pid;
typedef pair<double,double> pdd;
typedef pair<Int,pii> pip;
typedef pair<double,Int> pdp;
typedef vector<Int> veci;
typedef vector<double> vecd;
typedef vector<int> veci;
typedef vector<ll> vecll;
typedef vector<double> vecd;
typedef vector<pii> vecpii;
typedef vector<veci> mati;
typedef vector<vecd> matd;
#define A first
#define B second
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (x).size()
#define CLR(x) memset(x,0,sizeof x)
#define pdebug() printf("%d\n",__LINE__)
#define REP(i,a,b) for(int i = (a);i <= (b);i++)
#define FORO(i,n) REP(i,0,(int)n-1)
#define FORI(i,n) REP(i,1,(int)n)
#define FORIT(i,t) for(auto i = t.begin();i != t.end();i++)
#define eps 1e-6
#define sqr(x) ((x)*(x))
#define dist(_a,_b) sqrt(sqr(_a.A-_b.A)+sqr(_a.B-_b.B))
#define norm(_a) sqrt(sqr(_a.A)+sqr(_a.B))
template<typename T>void getMin(T &a,T b) { if(a > b) a = b; }
template<typename T>void getMax(T &a,T b) { if(a < b) a = b; }
template<typename T> vector<T> getVector(const int n) { return vector<T>(n); }
template<typename T> vector<T> getVector(const int n, const T a) { return vector<T>(n, a); }
template<typename T> vector<T> getEmptyVector() { return vector<T>(); }
template<typename T> void appendAll(vector<T> &a, vector<T> b) { a.insert(a.end(), b.begin(), b.end()); }
// #define X first
// #define Y second
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const ll MOD = 1000000007;
const int MAXN = 1<<17;
const int inf = 1<<28;
const int NIL = -inf;
int popcount(int x)  { return __builtin_popcount(x); }
#define DUMP(a) \
    do { std::cout << #a " = " << (a) << ", "; } while(false)
#define DUMPLN(a) \
    do { std::cout << #a " = " << (a) << std::endl; } while(false)

const int MAX = 100010;
bool prime[MAX+1];

void eratos(int n) {
    for(int i = 0;i <= n;i++) prime[i] = 0;
    for(int i = 3;i <= n;i+=2) prime[i] = 1;
    prime[2] = 1;
    for(int i = 3;i * i <= n;i+=2) {
        if(!prime[i]) continue;
        for(int j = 2 * i;j <= n;j+=i)
            prime[j] = 0;
    }
}

vector<pii> factorize(int N) {
    eratos(sqrt(N) + 1);
    vector<pii> ret;
    int tmp = N;
    for(int p = 2;p * p <= N;p++) {
        if(prime[p]) {
            int e = 0;
            while(tmp % p == 0) {
                tmp /= p;
                e++;
            }
            if(e) {
                ret.EB(pii(p, e));
            }
            // cout << "p, e = " << p << " " << e << endl;
        }
    }
    if(tmp > 1) ret.EB(pii(tmp, 1));
    return ret;
}

int N, K;
veci A;
int ans = 0;

ll ipow(ll a, int k) {
    if(k == 0) return 1;
    if(k & 1) return ipow(a, k - 1) * a;
    else { ll t = ipow(a, k / 2LL); return t * t; }
}

bool check(int m) {
    auto B = getVector<int>(N);
    transform(ALL(A), B.begin(), [m](int x){ return x % m; });
    sort(ALL(B));
    FORO(i, N) {
        int tota = 0, totb = 0;
        FORO(j, N) {
            if(j <= i) tota += B[j];
            else totb += m - B[j];
        }
        if(tota == totb && tota <= K) return true;
    }
    return false;
}

void rec(int m, int i, vecpii &pfe) {
    if(i == SZ(pfe)) {
        // DUMPLN(m);
        if(check(m)) {
            getMax(ans, m);
        }
        return ;
    }
    FORO(j, pfe[i].B + 1) {
        rec(m * ipow(pfe[i].A, j), i + 1, pfe);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    A.resize(N);
    int tot = 0;
    FORO(i, N) {
        cin >> A[i];
        tot += A[i];
    }
    sort(ALL(A));
    auto pfe = factorize(tot);
    rec(1, 0, pfe);

    cout << ans << endl;

    return 0;
}