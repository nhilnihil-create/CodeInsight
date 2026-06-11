#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> light(h, vector<int>(w));

    rep(i,h) {
        rep(j,w) {
            if (s[i][j] == '#') continue;
            int nj = j;
            while (nj+1 < w) {
                if (s[i][nj+1] == '#') break;
                nj++;
            }
            for (int k = j; k <= nj; k++) {
                light[i][k] += nj-j+1;
            }
            j = nj+1;
        }
    }
    rep(i,w) {
        rep(j,h) {
            if (s[j][i] == '#') continue;
            int nj = j;
            while (nj+1 < h) {
                if (s[nj+1][i] == '#') break;
                nj++;
            }
            for (int k = j; k <= nj; k++) {
                light[k][i] += nj-j+1;
            }
            j = nj+1;
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w) {
        ans = max(ans, light[i][j]-1);
    }
    cout << ans << endl;
    return 0;
}