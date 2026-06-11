#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};


const int MAX = 5100000; //必要な分だけ用意
ll fac[MAX], finv[MAX], inv[MAX];

//前処理 O(n)
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod/i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

//二項係数計算 O(1)
ll COM(int n, int k) {
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main() {
    int x, y; cin >> x >> y;
    ll ans = 0;
    COMinit();
    rep(i,x/2+1) { //i:右に2の移動の回数
        int nx = x-2*i, ny = y-i;
        if (nx<0 || ny<0) break;
        if (ny != 2*nx) continue;
        int step = nx;
        ans += COM(i+step,i);
        ans %= mod;
        if (ans<0) ans += mod;
    }
    cout << ans << endl;
}