#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;

    vector<int> ans(n);
    for (int i=0; i<n; i++) {
        queue<pair<int, int>> q;
        q.push({i, 0});
        vector<bool> vis(n);
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (vis[cur.first]) continue;
            if (cur.first > i)
                ans[cur.second]++;
            vis[cur.first] = true;
            if (cur.first != n-1) q.push({cur.first+1, cur.second+1});
            if (cur.first != 0) q.push({cur.first-1, cur.second+1});
            if (cur.first == x) q.push({y, cur.second+1});
        }
    }
    for (int i=1; i<n; i++) cout << ans[i] << "\n";
}
