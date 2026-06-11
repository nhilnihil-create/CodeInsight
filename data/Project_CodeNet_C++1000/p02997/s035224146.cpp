#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    vvi G(n, vi(n, 1));

    if (k > 0) {
        rep(i, 1, n) {
            rep(j, 1, n - i) {
                // j : j + i
                G[j][j + i] = 2;
                ++cnt;
                if (cnt == k) { break; }
            }
            if (cnt == k) { break; }
        }
    }

    if (cnt != k) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if (G[i][j] == 1) { ++ans; }
        }
    }

    cout << ans << endl;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if (G[i][j] == 1) { cout << i + 1 << " " << j + 1 << endl; }
        }
    }

    return 0;
}