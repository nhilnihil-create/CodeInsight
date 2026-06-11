#include <bits/stdc++.h>
 
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
 
#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=(int)(a)-1;i>=(int)(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)
 
#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define bit(n) (1LL<<(n))
 
// #define DEBUG
 
#ifdef DEBUG
    #define dump(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dump(...)
#endif
 
template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}
 
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
 
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll MOD = 1000000007LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
ll extgcd(ll a,ll b,ll& x,ll& y){x=1,y=0;ll g=a;if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;return g;}
ll ADD(const ll &a, const ll &b, const ll mod=MOD) { return (a+b)%mod;}
ll SUB(const ll &a, const ll &b, const ll mod=MOD) { return (a-b+mod)%mod;}
ll MUL(const ll &a, const ll &b, const ll mod=MOD) { return (1LL*a*b)%mod;}
ll DIV(const ll &a, const ll &b, const ll mod=MOD) {ll x,y; extgcd(b,mod,x,y);return MUL(a,(x+mod)%mod,mod);}
 
///////////////////////
const int N = 1e6; 
const int mod_ = MOD;

ll fact[N+1];

void set_fact() {
    fact[0] = 1;
    rep(i,N) fact[i+1] = ((((ll)i+1) % mod_) * fact[i]) % mod_;
}

ll mod_inv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

// n! mod_ p 
ll mod_fact(ll n, ll p, ll &e) {
    e = 0;
    if (!n) return 1;
    ll res = mod_fact(n/p, p, e);
    e += n/p;

    if ((n/p)%2) 
        return res * (p - fact[n%p]) %p;
    else
        return res * fact[n%p] % p;
}

// nCk mod_ p ; O(log_p n)
ll mod_comb(ll n, ll k, ll p) {
    if (n<0 || k<0 || n<k) return 0;
    ll e1, e2, e3;
    ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n-k, p, e3);
    if (e1 > e2+e3) return 0;
    return a1 * mod_inv(a2*a3%p, p) % p;
}

// nHk mod_ p ;
ll mod_h_comb(ll n, ll k, ll p) {
    return mod_comb(n+k-1, k, p);
}
///////////////////////

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, B; cin >> n >> B;
    int R = n - B;

    set_fact();

    rep(i, 1, B+1){
        ll fB = B - i;
        ll fR = R - (i-1);

        ll res = 0;
        if(fR >= 0){
            ll curB = DIV(fact[fB + i - 1], MUL(fact[fB], fact[i - 1]));
            ll curR = DIV(fact[fR + i], MUL(fact[fR], fact[i]));
            res = MUL(curB, curR);
        }

        cout << res << endl;
    }

    return 0;
}
