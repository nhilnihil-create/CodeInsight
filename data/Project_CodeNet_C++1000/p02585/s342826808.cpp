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


int main() {
    int n,k; cin >> n >> k;
    vector<int> p(n), c(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> c[i];
    rep(i,n) p[i]--;
    ll ans = -INF;
    rep(si,n) { //スタート位置全探索
        int x = si;
        vector<int> s; //サイクルの得られるスコアを格納
        ll tot = 0; //サイクルの総和
        while (1) {
            x = p[x];
            s.push_back(c[x]);
            tot += c[x];
            if (x == si) break; //始点に戻ってきたら終了
        }
        int l = sz(s); //周期の長さ
        ll t = 0;
        rep(i,l) { //サイクルを回っていく
            t += s[i];
            if (i+1>k) break;
            ll now = t;
            if (tot>0) { //サイクル総和正なら足せるサイクル分足す
                ll e = (k-(i+1))/l;
                now += tot*e;
            }
            chmax(ans,now);
        }
    }
    cout << ans << endl;
}