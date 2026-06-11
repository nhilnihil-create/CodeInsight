#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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
#define INF 1e9
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
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(h + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i + 1][min(h, j + a[i])], dp[i + 1][j] + b[i]);
        }
    }
    cout << dp[n][h] << endl;
}