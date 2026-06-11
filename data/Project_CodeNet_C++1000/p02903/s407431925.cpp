#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    mat res(h, vec(w, 1));

    rep(i, h) rep(j, w) {
        if (j < a && i < b) res[i][j] = 0;
        else if (j >= a && i >= b) res[i][j] = 0;
    }

    rep(i, h) {
        rep(j, w) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}