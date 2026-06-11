#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    vector<vector<int>> up(H, vector<int>(W)), down(H, vector<int>(W)),
        left(H, vector<int>(W)), right(H, vector<int>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> G[i][j];
            if (G[i][j] == '.')
                up[i][j] = 1, down[i][j] = 1, left[i][j] = 1, right[i][j] = 1;
        }
    }

    rep(i, H) {
        rep(j, W - 1) {
            left[i][j + 1] += left[i][j];
            if (G[i][j + 1] == '#')
                left[i][j + 1] = 0;
        }
    }

    rep(i, H) {
        for (int j = W - 1; j > 0; j--) {
            right[i][j - 1] += right[i][j];
            if (G[i][j - 1] == '#')
                right[i][j - 1] = 0;
        }
    }

    rep(j, W) {
        rep(i, H - 1) {
            down[i + 1][j] += down[i][j];
            if (G[i + 1][j] == '#')
                down[i + 1][j] = 0;
        }
    }

    rep(j, W) {
        for (int i = H - 1; i > 0; i--) {
            up[i - 1][j] += up[i][j];
            if (G[i - 1][j] == '#')
                up[i - 1][j] = 0;
        }
    }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (G[i][j] == '#')
                continue;
            ll tmp = left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3;
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}