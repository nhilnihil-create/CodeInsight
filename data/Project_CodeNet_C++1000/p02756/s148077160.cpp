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
#define INF 2e9
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
    string s; cin >> s;
    deque<char> que;
    for (char c : s) que.pb(c);
    bool flip = false;
    int q; cin >> q;
    rep(i,q) {
        int ty; cin >> ty;
        if (ty == 1) {
            flip = !flip;
        }
        else {
            int f; char c;
            cin >> f >> c;
            if (flip) f = 3-f;
            if (f==1) que.push_front(c);
            else que.push_back(c);
        }
    }
    if (flip) reverse(all(que));
    for (char c : que) cout << c;
    cout << endl;
}