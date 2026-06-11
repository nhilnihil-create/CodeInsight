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
using pi = pair<int, int>;
using vp = vector<pi>;
using Graph = vector<vector<int>>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

signed main() {
    int n, k;
    cin >> n >> k;

    Graph g(n, vi());

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dp(n, -1);

    queue<int> q;
    q.push(0);
    dp[0] = 0;
    int ans = k;

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v: g[u]) {
            if (dp[v] == -1) {
                dp[u] += 1;
                dp[v] = 1;
                ans *= (k - dp[u]);
                ans %= P;
                q.push(v);
            }
        }
    }

    cout << ans;
 
    return 0;
}
