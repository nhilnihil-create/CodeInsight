#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

signed main() {
    int h, n;
    cin >> h >> n;

    int dp[20001];
    rep(i, 20001) { dp[i] = INT_MAX; }
    dp[0] = 0;
    vector<pair<int, int>> v;
    int max = 0;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        chmax(max, a);
        v.push_back(make_pair(a, b));
    }

    rep(i, h + max) {
        for (auto p: v) {
            if (i + p.first <= 20000) {
                chmin(dp[i + p.first], dp[i] + p.second);
            }
        }
    }

    int ans = INT_MAX;
    rep(j, max + 1) {
        chmin(ans, dp[j + h]);
    }

    cout << ans;

    return 0;
}