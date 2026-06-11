#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<tuple<int, int, int, int>>> v(H, vector<tuple<int, int, int, int>>(W, make_tuple(0, 0, 0, 0)));
    vector<string> s(H);
    REP(i, H) {
        cin >> s[i];
    }
    REP(i, H) {
        int left = -1;
        REP(j, W) {
            if(s[i][j] == '#') {
                left = j;
            }else{
                v[i][j] = make_tuple(left, 0, 0, 0);
            }
        }
        int right = W;
        for(int j = W - 1;0 <= j;j--) {
            if(s[i][j] == '#') {
                right = j;
            }else{
                int l;
                tie(l, ignore, ignore, ignore) = v[i][j];
                v[i][j] = make_tuple(l, right, 0, 0);
            }
        }
    }

    REP(j, W) {
        int up = -1;
        REP(i, H) {
            if(s[i][j] == '#') {
                up = i;
            }else{
                int l, r;
                tie(l, r, ignore, ignore) = v[i][j];
                v[i][j] = make_tuple(l, r, up, 0);
            }
        }
        int down = H;
        for(int i = H - 1;0 <= i;i--) {
            if(s[i][j] == '#') {
                down = i;
            }else{
                int l, r, u;
                tie(l, r, u, ignore) = v[i][j];
                v[i][j] = make_tuple(l, r, u, down);
            }
        }
    }

    int res = -1;
    REP(i, H) {
        REP(j, W) {
            int l, r, u, d;
            tie(l, r, u, d) = v[i][j];
            if(l < r && u < d) {
                res = max(res, (r - l) + (d - u) - 3);
            }
        }
    }
    cout << res << endl;
    return 0;
}
