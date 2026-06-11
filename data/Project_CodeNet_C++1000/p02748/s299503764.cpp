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
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> A(a);
    vector<int> B(b);
    rep(i, a) cin >> A[i];
    rep(i, b) cin >> B[i];
    vector<int> x(m);
    vector<int> y(m);
    vector<int> c(m);
    rep(i, m) cin >> x[i] >> y[i] >> c[i];
    int ans =
        *min_element(A.begin(), A.end()) + *min_element(B.begin(), B.end());
    rep(i, m) chmin(ans, A[x[i] - 1] + B[y[i] - 1] - c[i]);
    cout << ans << endl;
}