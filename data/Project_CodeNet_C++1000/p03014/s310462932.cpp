#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF INT32_MAX / 2
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

using namespace std;
//#inculude <bits/stdc++.h>
//#define int long long

signed main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];
    vector<vector<int>> xtable(h, vector<int>(w, 0));
    vector<vector<int>> ytable(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            if (grid[i][j] == '.' && j != w - 1) {
                if (j == 0)
                    xtable[i][j] = 1;
                else
                    xtable[i][j] = xtable[i][j - 1] + 1;
            }
            else if (j == w - 1 && grid[i][j] == '.') {
                if (w == 1)
                    xtable[i][j] = 1;
                else
                    xtable[i][j] = xtable[i][j - 1] + 1;
                for (int k = j; k >= 0 && grid[i][k] == '.'; k--)
                    xtable[i][k] = xtable[i][j];
            }
            else if (j != 0) {
                for (int k = j - 1; k >= 0 && grid[i][k] == '.'; k--)
                    xtable[i][k] = xtable[i][j - 1];
            }
        }
    }

    rep(i, w) {
        rep(j, h) {
            if (grid[j][i] == '.' && j != h - 1) {
                if (j == 0)
                    ytable[j][i] = 1;
                else
                    ytable[j][i] = ytable[j - 1][i] + 1;
            }
            else if (j == h - 1 && grid[j][i] == '.') {
                if (h == 1)
                    ytable[j][i] = 1;
                else
                    ytable[j][i] = ytable[j - 1][i] + 1;
                for (int k = j; k >= 0 && grid[k][i] == '.'; k--)
                    ytable[k][i] = ytable[j][i];
            }
            else if (j != 0) {
                for (int k = j - 1; k >= 0 && grid[k][i] == '.'; k--)
                    ytable[k][i] = ytable[j - 1][i];
            }
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w) chmax(ans, xtable[i][j] + ytable[i][j] - 1);
    cout << ans << endl;
#ifdef LOCAL
    ans = 0;
    int maxi, maxj;
    rep(i, h) rep(j, w) if (chmax(ans, xtable[i][j] + ytable[i][j] - 1))
        maxi = i,
        maxj = j;
    cout << ans << endl;
    cout << "i : " << maxi << endl;
    cout << "j : " << maxj << endl;
    rep(i, h) {
        rep(j, w) {
            cout << xtable[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    rep(i, h) {
        rep(j, w) {
            cout << ytable[i][j] << ' ';
        }
        cout << '\n';
    }
#endif
}