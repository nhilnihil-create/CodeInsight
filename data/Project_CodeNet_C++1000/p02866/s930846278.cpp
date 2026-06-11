#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
constexpr int mod = 998244353;
template <class T> T modpow(T a, T b) {
    if (b == 0) return T(1);
    if (b % 2 == 0) {
        long long d = modpow(a, b / T(2));
        return (d * d) % mod;
    } else {
        return (a * modpow(a, b - 1) % mod );
    }
}
template<class T> T mod_nCr(T n, T r, T mod ) {
    T denom = 1;
    T numer = 1;
    for (T i = 1; i <= r; i++) numer = (numer * i) % mod;
    for (T i = n - r + 1; i <= n; i++) denom = (denom * i) % mod;
    return (denom * modpow(numer, mod - 2) % mod);
}
signed main(){
    int N; cin >> N;
    vector<int>v(N);
    for(auto& e : v) cin >> e;
    map<int,int>cnt;
    for(auto e : v) cnt[e]++;
    int ans = (v.front() == 0);
    for(auto itr : cnt){
        if(itr.first == 0){
            if(itr.second != 1) ans = 0;
        } else {
            if(cnt[itr.first - 1] == 0) ans = 0;
            else ans *= modpow(cnt[itr.first - 1],itr.second);
        }
        ans %= mod;
    }
    cout << ans << endl;
}

