#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> jobs(100001);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        jobs[a].push_back(b);
    }

    int ans = 0;
    priority_queue<int> pq;
    for (int i = 1; i <= m; i++) {
        rep(j, jobs[i].size()) pq.push(jobs[i][j]);
        if (!pq.empty()) {
            // cout << i << " " << pq.top() << endl;
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
