#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};


int main() {
    vector<vector<int>> a(3,vector<int>(3));
    rep(i,3)rep(j,3) {
        cin >> a[i][j];
    }
    int n; cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    rep(i,n) {
        rep(j,3)rep(k,3) {
            if (b[i]==a[j][k]) {
                a[j][k] = 0;
                break;
            }
        }
    }
    bool check = false;
    rep(i,3) {
        if (a[i][0]+a[i][1]+a[i][2]==0) {
            check = true;
            break;
        }
        if (a[0][i]+a[1][i]+a[2][i]==0) {
            check = true;
            break;
        }
    }
    if (a[0][0]+a[1][1]+a[2][2]==0) check = true;
    if (a[0][2]+a[1][1]+a[2][0]==0) check = true;
    if (check) cout << "Yes" << endl;
    else cout << "No" << endl;
}