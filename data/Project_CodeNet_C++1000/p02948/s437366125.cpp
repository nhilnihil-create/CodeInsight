#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using llong = long long;

pair<llong, llong> a[100005];
priority_queue<llong> p_que;

int main() {
    llong n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    llong ans = 0;
    int idx = 0;
    sort(a, a + n);

    for (int i = m - 1; i >= 0; i--) {
        while (idx < n && a[idx].first <= (m - i)) {
            p_que.push(a[idx].second);
            idx++;
        }

        if (p_que.empty()) continue;
        ans += p_que.top();
        p_que.pop();
    }
    cout << ans << endl;
}