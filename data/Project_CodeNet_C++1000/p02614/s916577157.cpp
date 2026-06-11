#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int h, w, k; cin >> h >> w >> k;
    vector<vector<char>> g(h, vector<char>(k));

    int totalcnt = 0;

    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            g[i][j] = s[j];
            if (s[j] == '#') totalcnt++;
        }
    }

    int ans = 0;

    for (unsigned int rows = 0; rows < 1<<(h); rows++) {
        for (unsigned int cols = 0; cols < 1<<(w); cols++) {
            vector<vector<bool>> m(h, vector<bool>(w, false));
            for (int r = 0; r < h; r++) {
                if (rows & (1<<r)) {
                    for (int j = 0; j < w; j++) m[r][j] = true;
                }
            }
            for (int c = 0; c < w; c++) {
                if (cols & (1<<c)) {
                    for (int i = 0; i < h; i++) m[i][c] = true;
                }
            }

            int remcnt = 0;
            for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if (m[i][j] && g[i][j] == '#') remcnt++;

            if (totalcnt - remcnt == k) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}