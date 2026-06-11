#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 5;
vector<int> jobs[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (m - a + 1 > 0)
            jobs[m - a + 1].push_back(b);
    }
    priority_queue<int> pq;
    int ans = 0;
    for (int i = m; i >= 1; i--) {
        for (auto x:jobs[i]) pq.push(x);
        if (pq.size()) ans += pq.top(), pq.pop();
    }
    cout << ans << endl;
    return 0;
}