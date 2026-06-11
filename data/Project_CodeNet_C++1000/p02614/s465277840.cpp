#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    ll count = 0;
    rep(mi, 1<<h) rep(mj, 1<<w) {
        int blck = 0;
        rep(i,h) rep(j,w) {
            if ( !((mi>>i)&1) && !((mj>>j)&1) && c[i][j] == '#') blck++;
        }
        if (blck == k) count++;
    }
    cout << count << endl;
    return 0;
}