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
    int n,m,x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i,n) {
        cin >> c[i];
        rep(j,m) {
            cin >> a[i][j];
        }
    }
    int money = INF;
    bool ok = false;
    rep(i,1<<n) {
        int tmp = 0;
        bool ok1 = true;
        vector<int> rikai(m,0);
        rep(j,n) {
            if (i>>j & 1) {
                tmp += c[j];
                rep(k,m) {
                    rikai[k] += a[j][k];
                }
            }
        }
        rep(k,m) {
            if (rikai[k] < x) {
                ok1 = false;
                break;
            }
        }
        if (ok1) {
            ok = true;
            chmin(money, tmp);
        }
    }
    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << money << endl;
    }
}