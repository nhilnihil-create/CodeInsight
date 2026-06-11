#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isIn(x,y,h,w) (x >= 0 && x < h && y >= 0 && y < w)
#define int long long
#define debug(var) cout << "[" << #var << "] " << var << endl
//using ll = long long;

const int INF=1e+18;
const double EPS=1e-9;
const int MOD=998244353;

signed main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> map(h, vector<char>(w));
    vector<vector<int>> count(h, vector<int>(w));

    rep(i, h) {
        vector<char> tmp(w);
        vector<int> tmp_count(w, 0);
        rep(j, w) {
            cin >> tmp.at(j);
        }
        map[i] = tmp;
        count[i] = tmp_count;
    }

    if (map[0][0] == '.') {
        count[0][0] = 0;
    } else {
        count[0][0] = 1;
    }
    FOR(j, 1, w) {
        if (map[0][j-1] == '.' && map[0][j] == '#') {
            count[0][j] = count[0][j-1] + 1;
        } else {
            count[0][j] = count[0][j-1];
        }
    }
    FOR(i, 1, h) {
        if (map[i-1][0] == '.' && map[i][0] == '#') {
            count[i][0] = count[i-1][0] + 1;
        } else {
            count[i][0] = count[i-1][0];
        }
    }

    FOR(i, 1, h) {
        FOR(j, 1, w) {
            int up, left;

            if (map[i][j-1] == '.' && map[i][j] == '#') {
                left = count[i][j-1] + 1;
            } else {
                left = count[i][j-1];
            }

            if (map[i-1][j] == '.' && map[i][j] == '#') {
                up = count[i-1][j] + 1;
            } else {
                up = count[i-1][j];
            }

            count[i][j] = min(left, up);
        }
    }

    // rep(i, h) {
    //     rep (j, w) {
    //         cout << count[i][j];
    //     }
    //     cout << endl;
    // }

    cout << count[h-1][w-1];

}