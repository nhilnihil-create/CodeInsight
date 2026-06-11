#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int dp[3050][8000];

int main() {
    int n, t;
    cin >> n >> t;
    vec a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<P> p(n);
    rep(i, n) p[i] = make_pair(a[i], b[i]);

    sort(all(p));

    rep(i, 3010) rep(j, 8000) dp[i][j] = 0;

    int res = 0;

    rep(i, n) {
        int ni = i+1;
        rep(j, t) {
            chmax(dp[ni][j], dp[i][j]);
            chmax(dp[ni][j+p[i].first], dp[i][j] + p[i].second);
            chmax(res, dp[i][j] + p[i].second);
        }
    }

    cout << res << endl;
    return 0;
}