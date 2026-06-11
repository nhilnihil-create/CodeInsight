#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

int dp[3003][3003] = {0};

signed main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> vp;

    rep(i, n) {
        int a, b;
        cin >> a >> b;

        vp.push_back({a, b});
    }

    sort(all(vp), [](const auto& l, const auto& r) { return l.first < r.first; });

    dp[0][0] = 0;

    rep(j, n) {
        for(int i = 0; i <= t; ++i) {
            chmax(dp[i + 1][j + 1], dp[i][j + 1]);
            chmax(dp[i + 1][j + 1], dp[i + 1][j]);
            if (i + vp[j].first <= t) {
                chmax(dp[i + vp[j].first][j + 1], dp[i][j] + vp[j].second);
            }
        }
    }

    int ans = 0;
    rep(j, n) {
        chmax(ans, dp[t - 1][j] + vp[j].second);
    }

    // dev(dp, t + 1, n + 1);

    cout << ans;

    return 0;
}