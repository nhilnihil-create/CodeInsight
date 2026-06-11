#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

using ull = unsigned long long;
using vull = V<ull>;

bitset<64> even1;
bitset<64> atleast1;

void pr(V<bitset<64>>& a){
    rep(i, SZ(a)){
        cerr << a[i] << " \n"[i==SZ(a)-1];
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vull a(n);
    vull ae(n, 0); // 見るビットを詰めたもの
    V<bitset<64>> aeb(n);
    rep(i, n){
        cin >> a[i];
        even1 ^= a[i];
        atleast1 |= a[i];
    }
    even1.flip();
    even1 &= atleast1;
    rep(i, n){
        ll c = 0;
        rep(j, 64){
            if(even1[j]){
                ae[i] += (((a[i] >> j) & 1) << c);
                c++;
            }
        }
        aeb[i] = ae[i];
    }
    // 掃き出し法
    int rank_ = 0;
    repb(b, 64){
        repr(i, rank_, n){
            if(aeb[i][b]){
                swap(aeb[i], aeb[rank_]);
                break;
            }
        }
        if(aeb[rank_][b]){
            repr(i, rank_+1, n){
                if(aeb[i][b]) aeb[i] ^= aeb[rank_];
            }
            rank_++;
        }
        if(rank_ >= n) break;
    }
    rep(i, n) dump(bitset<64>(a[i]));
    rep(i, n) dump(aeb[i]);
    ull ans = 0;
    rep(i, n){
        chmax(ans, ans ^ aeb[i].to_ullong());
    }
    dump(even1);
    ll ans2 = 0;
    {
        ll c = 0;
        rep(j, 64){
            if(even1[j]){
                ans2 += (((ans >> c) & 1) << j);
                dump(bitset<64>(ans2));
                c++;
            }
        }
    }
    ans2 <<= 1;
    {
        rep(j, 64){
            if(!even1[j] && atleast1[j]){
                ans2 += (1ll << j);
                dump(bitset<64>(ans2));
            }
        }
    }
    cout << ans2 << endl;
    return 0;
}