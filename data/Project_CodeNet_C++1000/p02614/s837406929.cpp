#include <bits/stdc++.h>

using namespace std;

using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int INF = 1<<30;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
 
    int num_black = 0;
    rep(i, h) rep(j, w) num_black += static_cast<int>(c[i][j] == '#');

    int ans = 0;
    for (int bi = 0; bi < (1<<h); ++bi) {
        for (int bj = 0; bj < (1<<w); ++bj) {
            int tmp = num_black;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) if ((bi&(1<<i) || bj&(1<<j)) && c[i][j] == '#') --tmp;
            }
            // cout << bi << ' ' << bj << ' ' << tmp << endl;
            ans += static_cast<int>(tmp == k);
        }
    }

    cout << ans << endl;

    return 0;
}