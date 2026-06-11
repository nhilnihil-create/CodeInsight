#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr.begin(), arr.end());
    priority_queue<int> pq;
    int ans = 0, pos = 0;

    for (int i = 1; i <= m; i++) {
        while (pos < n && arr[pos].first <= i) {
            auto t = arr[pos];
            pq.push(t.second);
            pos++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
}