#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        q.push({b[i], i});
    }
    long long ans = 0;
    while (q.size() > 0) {
        int i = q.top().second;
        q.pop();
        if (b[i] < a[i]) {
            ans = -1;
            break;
        }
        if (b[i] > a[i]) {
            int d = b[(n + i - 1) % n] + b[(i + 1) % n];
            int c = (b[i] - a[i]) / d;
            if (c == 0) {
                ans = -1;
                break;
            }
            ans += c;
            b[i] -= c*d;
            q.push({b[i], i});
        }
    }
    cout << ans << endl;
}



