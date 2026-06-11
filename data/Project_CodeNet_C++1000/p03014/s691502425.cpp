#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> x(h, vector<int>(w)), y(h, vector<int>(w));
    rep(i,h) {
        rep(j,w) {
            if (s[i][j] == '#') continue;
            int l = 0;
            l = j;
            while (j < w && s[i][j] == '.') j++;
            int r = j;
            for (int k = l; k <= r-1; k++) x[i][k] = r-l; 
        }
    }
    rep(j,w) {
        rep(i,h) {
            if (s[i][j] == '#') continue;
            int l = 0;
            l = i;
            while (i < h && s[i][j] == '.') i++;
            int r = i;
            for (int k = l; k <= r-1; k++) y[k][j] = r-l; 
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') continue;
        ans = max(x[i][j]+y[i][j]-1, ans);
    } 
    cout << ans << endl;
    return 0;
}