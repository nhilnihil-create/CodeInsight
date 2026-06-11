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
    int h,w,m; cin >> h >> w >> m;
    vector<P> b(m);
    rep(i,m) cin >> b[i].first >> b[i].second;
    set<P> st;
    rep(i,m) st.insert(b[i]);
    map<int,int> mph, mpw;
    rep(i,m) {
        mph[b[i].first]++;
        mpw[b[i].second]++;
    }
    int nh = 0, nw = 0;
    for (auto x : mph) {
        chmax(nh, x.second);
    }
    for (auto x : mpw) {
        chmax(nw, x.second);
    }
    set<int> sth, stw;
    for (auto x : mph) {
        if (x.second == nh) sth.insert(x.first);
    }
    for (auto x : mpw) {
        if (x.second == nw) stw.insert(x.first);
    }

    for (auto x : sth) { //重複しないやつがあるか調査
        for (auto y : stw) {
            if (st.find(P(x,y)) == st.end()) {
                cout << nh + nw << endl;
                return 0;
            }
        }
    }

    cout << nh + nw - 1 << endl;

}