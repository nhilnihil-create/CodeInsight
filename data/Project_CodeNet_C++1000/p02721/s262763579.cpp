#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    vector<int> dpf(n+1), dpb(n+1);
    int pre = -INF;
    for (int i=1; i<n+1; ++i) {
        dpf.at(i) = dpf.at(i-1);
        if (s.at(i-1) == 'o' && i - pre > c) {
            ++dpf.at(i);
            pre = i;
        }
    }
    pre = INF;
    for (int i=n-1; i>=0; --i) {
        dpb.at(i) = dpb.at(i+1);
        if (s.at(i) == 'o' && pre - i > c) {
            ++dpb.at(i);
            pre = i;
        }
    }
    for (int i=0; i<n; ++i) {
        if (dpf.at(i) + dpb.at(i+1) < k) {
            cout << i+1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
