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

int main() {
    int n, m;
    cin >> n >> m;
    vec a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vec job[100050];
    rep(i, n) {
        job[a[i]].push_back(b[i]);
    }

    lint res = 0;

    priority_queue<int> que;

    for (int d = 1; d <= m; d++) {
        for (auto&& j : job[d]) que.push(j);
        if (!que.empty()) {
            res += que.top();
            que.pop();
        }
    }

    cout << res << endl;
    return 0;
}