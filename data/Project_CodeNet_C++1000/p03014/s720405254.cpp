#include <bits/stdc++.h>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr int INF = 1001001001;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    rep (i, h) {
        string s;
        cin >> s;
        rep (j, w) a[i][j] = s[j];
    }
    
    vector<vector<int>> dh(h, vector<int>(w, -INF));
    rep (i, h) rep (j, w) {
        if (dh[i][j] != -INF || a[i][j] == '#')
            continue;
        int l = j, r = j;
        while (0 < l && a[i][l-1] == '.') l--;
        while (r+1 < w && a[i][r+1] == '.') r++;
        rep (k, l, r+1) dh[i][k] = r-l+1;          
    }
    vector<vector<int>> dw(h, vector<int>(w, -INF));
    rep (i, w) rep (j, h) {
        if (dw[j][i] != -INF || a[j][i] == '#')
            continue;
        int u = j, d = j;
        while (0 < u && a[u-1][i] == '.') u--;
        while (d+1 < h && a[d+1][i] == '.') d++;
        rep (k, u, d+1) dw[k][i] = d-u+1;
    }
    
    int ans = 0;
    rep (i, h) rep (j, w) chmax(ans, dh[i][j] + dw[i][j] - 1);
    cout << ans << endl;
    
    return 0;
}
