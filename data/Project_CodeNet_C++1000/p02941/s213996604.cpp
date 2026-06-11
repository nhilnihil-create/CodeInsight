#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 9;

using lint = long long;

int a[maxn], b[maxn];
priority_queue<pair<int, int>> pq;

int main() {
#if DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        pq.push({b[i], i});
    }
    lint ans = 0;
    while (!pq.empty()) {
        pair<int, int> here = pq.top();
        pq.pop();
        if (b[here.second] <= a[here.second]) continue;
        int p = b[(here.second + n - 1) % n];
        int q = b[here.second];
        int r = b[(here.second + 1) % n];
        lint s = (q - a[here.second]) / (p + r);
        if (s == 0) {
            cout << "-1\n";
            return 0;
        }
        ans += s;
        q -= s * (p + r);
        b[here.second] = q;
        if (a[here.second] != b[here.second])
            pq.push({q, here.second});
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans << '\n';
}
