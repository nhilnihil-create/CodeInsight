#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    vector<vector<int>> v(m);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if (a > m) continue;
        v[m-a].push_back(b);
    }
    int ans = 0;
    for (int i = m-1; i >= 0; i--) {
        for (int x : v[i]) {
            q.push(x);
        }
        if (!q.empty()) {
            ans += q.top(); q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}