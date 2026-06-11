
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

int dp[1001][(1 << 12) + 1];

signed main() {
    int n, m;
    cin >> n >> m;

    rep(i, 1001) {
        rep(j, (1 << 12) + 1) {
            dp[i][j] = INT_MAX;
        }
    }

    vector<pair<int, int>> vk;

    rep(i, m) {
        int a, b;
        cin >> a >> b;

        int x = 0;
        rep(j, b) {
            capi(c); --c;
            x += 1 << c;
        }
        vk.push_back(make_pair(x, a));
    }

    dp[0][0] = 0;

    rep(i, m) {
        rep(j, 1 << n) {
            chmin(dp[i + 1][j | vk[i].first], dp[i][j] + vk[i].second);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }

   //  for(int i=0;i<(1 << n) + 1;++i){for(int j=0;j<m+1;++j){cout<<"|"<<dp[j][i];}cout<<"|"<<endl;}

    if (dp[m][(1 << n) - 1] >= INT_MAX) {
        cout << -1;
    } else {
        cout << dp[m][(1 << n) - 1];
    }

    return 0;
}