// Template
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <complex>
#include <cassert>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET{IOSET(){cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main Code
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    int sum = 0;
    rep(i, n) sum += a[i];
    vector<int> ds;
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            ds.push_back(i);
            ds.push_back(sum / i);
        }
    }
    
    int ans = 0;
    for (int d: ds) {
        vector<int> b = a;
        rep(i, n) b[i] %= d;
        sort(all(b));
        vector<ll> b_sum(n + 1, 0);
        rep(i, n) b_sum[i + 1] = b_sum[i] + b[i];
        vector<int> c = b;
        rep(i, n) c[i] = (c[i] + d - 1) / d * d - c[i];
        vector<ll> c_sum(n + 1, 0);
        rep(i, n) c_sum[i + 1] = c_sum[i] + c[i];
        ll mn = INF;
        rep(i, 1, n) chmin(mn, max(b_sum[i], c_sum[n] - c_sum[i]));
        if (mn <= k) chmax(ans, d);
    }
    
    cout << ans << "\n";
    return 0;
}
