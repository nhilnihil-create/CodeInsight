#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int dp[3001];

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    fill(dp, dp + t + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = t - 1; j >= 0; --j) {
            if (dp[j] >= 0) {
                chmax(dp[min(t, j + a[i].first)], dp[j] + a[i].second);
            }
        }
    }
    cout << *max_element(dp, dp + t + 1) << endl;

    return 0;
}