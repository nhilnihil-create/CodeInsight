#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20)
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

int h, w;
string b[2222];
int
    l[2222][2222] = {},
    r[2222][2222] = {},
    u[2222][2222] = {},
    d[2222][2222] = {};

signed main() {
    INCANT;
    cin>>h>>w;
    for (int i = 0; i < h; i++) {
        cin>>b[i];
        int now = 1;
        for (int j = 0; j < w; j++) {
            if (b[i][j] == '#') now = 0;
            else l[i][j] = now;
            now++;
        }
        now = 1;
        for (int j = w - 1; j >= 0; j--) {
            if (b[i][j] == '#') now = 0;
            else r[i][j] = now;
            now++;
        }
    }
    for (int j = 0; j < w; j++) {
        int now = 1;
        for (int i = 0; i < h; i++) {
            if (b[i][j] == '#') now = 0;
            else u[i][j] = now;
            now++;
        }
        now = 1;
        for (int i = h - 1; i >= 0; i--) {
            if (b[i][j] == '#') now = 0;
            else d[i][j] = now;
            now++;
        }
    }
    int res = -INF;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res = max(res, l[i][j] + r[i][j] + u[i][j] + d[i][j]);
        }
    }
    cout<<res - 3<<endl;
}