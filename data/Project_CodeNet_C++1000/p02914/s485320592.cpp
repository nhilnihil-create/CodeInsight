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

template <typename T>
int find_left(vector<T>& v, T elem) {
    return (int)(upper_bound(v.begin(), v.end(), elem) - v.begin()) - 1;
}
template <typename T>
int find_right(vector<T>& v, T elem) {
    return (int)(lower_bound(v.begin(), v.end(), elem) - v.begin());
}

const ll MOD=1000000007LL;

inline ll ADD(ll x, ll y) { return (x+y) % MOD; }
inline ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
inline ll MUL(ll x, ll y) { return x*y % MOD; }
inline ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
inline ll INV(ll y) { /*assert(y%MOD!=0);*/ return POW(y, MOD-2); }
inline ll DIV(ll x, ll y) { return MUL(x, INV(y)); }
#define INTSPACE 22
char _buf[INTSPACE*1000000 + 3];

long long loadint() {
    if (fgets(_buf, INTSPACE+3, stdin)==NULL) return 0;
    return strtoll(_buf, NULL, 10);
}

int loadvecll(vector<long long>& v, int N=-1) {
    if (N == 0) {
        v.clear();
        return 0;
    }
    if (N == -1) {
        N = (int)loadint();
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
        v[i++] = strtoll(p, NULL, 10);
        if (last || i == N) break;
        p = q+1;
    }
    return i;
}
void read_cr() {
    fgets(_buf, 256, stdin);
}


template<typename T>
struct xorset {
    vector<T> basis;


    xorset(vector<T>& a){
        for (T ai : a) {
            for (T b : basis)
                amin(ai, ai ^ b);
            if (ai) basis.pb(ai);
        }
    }

    T maxval() {
        T res = 0;
        for (T b : basis)
            amax(res, res ^ b);
        return res;
    }


};


ll solve(int N, vll& a) {
    ll U=0;
    rep(i,N) U ^= a[i];

    rep(i,N) a[i] &= ~U;
    xorset<ll> xs(a);

    ll lower = U, upper = xs.maxval();
    return lower + (upper << 1);
}

int main() {
    vll a;
    int N = loadvecll(a);
    cout << solve(N,a) << endl;
    return 0;
}
