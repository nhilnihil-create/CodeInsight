#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#ifdef LOCAL
    freopen("input.in" , "r" , stdin);
#endif
    int n , m;
    cin >> n >> m;

    vector<int> adj[m + 1];
    for (int i = 1 ;i <= n ;i++) {
        int time , reward;
        cin >> time >> reward;
        if (time <= m)
            adj[time].push_back(reward);
    }

    int ans = 0;

    priority_queue<int> pq;
    for (int i = 1 ;i <= m ;i++) {
        for (int x : adj[i])
            pq.push(x);

        if (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}
