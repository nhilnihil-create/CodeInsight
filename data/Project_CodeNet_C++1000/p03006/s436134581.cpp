#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vi x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    int ans = 1e9;
    if(n == 1) ans = 1;
    REP(i, n) REP(j, n) {
        if(i == j) continue;
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        int sub = 0;
        REP(i1, n) REP(j1, n) {
            if(i1 == j1) continue;
            if(dx == x[i1] - x[j1] && dy == y[i1] - y[j1]) ++sub;
        }
        ans = min(ans, n - sub);
    }
    cout << ans << endl;
    // map<pair<int, int>, int> v;
    // REP(i, n) FOR(j, i + 1, n) {
    //     int x1 = x[j] - x[i];
    //     int y1 = y[j] - y[i];
    //     if(x1 < 0) {
    //         x1 = -x1;
    //         y1 = -y1;
    //     } else if(x1 == 0) {
    //         if(y1 < 0) {
    //             y1 = -y1;
    //         }
    //     }
    //     v[make_pair(x1, y1)]++;
    // }
    // int max_count = 0;
    // pii p;
    // for(auto& [key, val] : v) { // keyを取り出す
    //     if(val > max_count) {
    //         val = max_count;
    //         p = key;
    //     }
    // }

    

    return 0;
}