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
 
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vi idx(n);
    rep(i, n){
        int x; cin >> x;
        x--;
        idx[x] = i;
    }

    set<int> s1 = {idx.back(), n};
    set<int> s2 = {-idx.back(), 1};

    ll res = 0LL;
    rrep(x, n-1){
        int i = idx[x];

        // left
        int p2 = -(*s2.lower_bound(-i));
        int p1 = (p2 == -1 ? -1 : (-(*s2.upper_bound(-p2))));

        // right
        int p3 = *s1.lower_bound(i);
        int p4 = (p3 == n ? n : (*s1.upper_bound(p3)));

        ll cur = 0LL;

        // including p2
        if(p2 != -1){
            cur += 1LL * (p2 - p1) * (p3 - i);
        }

        // including p3
        if(p3 != n){
            cur += 1LL * (i - p2) * (p4 - p3);
        }

        res += (x + 1) * cur;

        s1.insert(i);
        s2.insert(-i);
    }

    cout << res << endl;

    return 0;
}
