#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>


typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<llll> vllll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define eb  emplace_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define repC3(vari,varj,vark,n)  for(int vari=0;vari<(n)-2;++vari)for(int varj=vari+1;varj<(n)-1;++varj)for(int vark=varj+1;vark<(n);++vark)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair
#define clamp(v,lo,hi) min(max(v,lo),hi)
#define ABS(x) max((x),-(x))
#define PQ(T) priority_queue<T,vector<T>,greater<T>>

template<typename T1, typename T2> inline void amin(T1 & a, T2 const & b) { if (a>b) a=b; }
template<typename T1, typename T2> inline void amax(T1 & a, T2 const & b) { if (a<b) a=b; }
template<typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template<typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

inline ll square(ll x) { return x * x; }
inline ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }
inline ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }
template <typename T>
inline T mod(T a, T b) { return ((a % b) + b) % b; }


#define INTSPACE 12
char _buf[INTSPACE*1000000 + 3];

int loadint() {
    if (fgets(_buf, INTSPACE+3, stdin)==NULL) return 0;
    return atoi(_buf);
}

int loadvec(vector<int>& v, int N=-1) {
    if (N == 0) {
        v.clear();
        return 0;
    }
    if (N == -1) {
        N = loadint();
        if (N==0) return 0;
    }
    int bufsize = INTSPACE*N + 3;
    if (fgets(_buf, bufsize, stdin)==NULL) return 0;
    v.resize(N);

    int i=0;
    bool last = false;
    for (char *p=&_buf[0]; ;) {
        char *q = p;
        while (*q > ' ') ++q;
        if (*q == 0x0D || *q == 0x0A) last = true;
        *q = 0;
        v[i++] = atoi(p);
        if (last || i == N) break;
        p = q+1;
    }
    return i;
}

ll dp[3001][3001];

ll solve(int N, int S, vi& a) {
    ll MOD = 998244353;
    mset(dp, 0);
    dp[0][0]=1;
    rep(i,N){
        int x = a[i];
        rep(n,3001){
            (dp[i+1][n] += (dp[i][n] * 2)) %= MOD;
            if (n+x <= 3000)
                (dp[i+1][n+x] += dp[i][n]) %= MOD;
        }
    }
    return dp[N][S];
}

int main() {
    int N, S; scanf("%d %d%*c", &N, &S);
    vi a(N);
    loadvec(a,N);
    cout << solve(N,S,a) << endl;
    return 0;
}

