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
const ll MOD = 1000000007;
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
#define int long long

template <class T>
void MODinit(T MAX, T M, vector<T> &fac, vector<T> &finv) {
    // fac,finvは空配列でok
    fac.resize(2, 1);
    finv.resize(2, 1);
    vector<T> inv(2, 1);
    for (T i = 2; i < MAX; i++) {
        fac.push_back(fac[i - 1] * i % M);
        inv.push_back(M - inv[M % i] * (M / i) % M);
        finv.push_back(finv[i - 1] * inv[i] % M);
    }
}

template <class T>
T com(T n, T k, vector<T> &fac, vector<T> &finv, T M) {
    // nCk
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % M) % M;
}

signed main() {
    int x, y;
    cin >> x >> y;
    if ((2 * y - x) % 3 != 0 || (2 * x - y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int a = (2 * y - x) / 3;
    int b = (2 * x - y) / 3;
    if (2 * y - x < 0 || 2 * x - y < 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> s(0);
    vector<int> t(0);
    ll max = 3000000;
    MODinit(max, MOD, s, t);
    cout << com(a + b, b, s, t, MOD) << endl;
}