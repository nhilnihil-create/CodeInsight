#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()


int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    rep (i, h) {
        string s;
        cin >> s;
        rep (j, w) {
            if (s[j] == '.') {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    vector<vector<int>> yoko(h, vector<int>(w, 0)), tate(h, vector<int>(w, 0));
    rep (i, h) {
        int ctr = 0;
        int lastidx = 0;
        rep (j, w) {
            if (grid[i][j]) {
                ctr++;
            } else {
                rep (k, lastidx, j) {
                    yoko[i][k] = ctr;
                }
                ctr = 0;
                yoko[i][j] = -1;
                lastidx = j + 1;
            }
            if (j == w - 1 && grid[i][j]) {
                rep (k, lastidx, w) {
                    yoko[i][k] = ctr;
                }
            }
        }
    }
    rep (i, w) {
        int ctr = 0;
        int lastidx = 0;
        rep (j, h) {
            if (grid[j][i]) {
                ctr++;
            } else {
                rep (k, lastidx, j) {
                    tate[k][i] = ctr;
                }
                ctr = 0;
                tate[j][i] = -1;
                lastidx = j + 1;
            }
            if (j == h - 1 && grid[j][i]) {
                rep (k, lastidx, h) {
                    tate[k][i] = ctr;
                }
            }
        }
    }
    int ans = 0;
    rep (i, h) {
        rep (j, w) {
            chmax(ans, yoko[i][j] + tate[i][j]);
        }
    }
    cout << ans - 1 << endl;
}
