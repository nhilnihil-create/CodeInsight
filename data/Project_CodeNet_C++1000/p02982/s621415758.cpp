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
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep (i, n) rep (j, d) cin >> x[i][j];
    
    int ans = 0;
    rep (i, n-1) rep (j, i+1, n) {
        int dist = 0;
        rep (k, d) dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
        //cout << i << ", " << j << ", " << dist << endl;
        rep (k, 128) if (k * k == dist) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
