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
    int h,w,k; cin >> h >> w >> k;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    int ans = 0;
    rep(i,1<<(h+w)) {
        int cnt = 0;
        set<int> st; //赤く塗る列を入れる
        rep(j,w) {
            if (i>>(h+j) & 1) st.insert(j);
        }
        rep(j,h) {
            if (i>>j & 1) { //i行目赤く塗るならば
                continue;
            }
            rep(k,w) {
                if (st.find(k)!=st.end()) continue;
                if (c[j][k]=='#') cnt++;
            }
        }
        if (cnt==k) ans++;
    }
    cout << ans << endl;
}