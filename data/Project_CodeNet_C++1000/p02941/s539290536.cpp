#include <queue>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] > b[i]) { cout << "-1\n"; return 0; }
        if (a[i] < b[i]) pq.push({b[i], i});
    }
    long long ans = 0;
    while (!pq.empty()) {
        int i = pq.top().second;
        pq.pop();
        int l = (i+n-1)%n, r = (i+1)%n;
        if (b[l] + b[r] > b[i] - a[i]) { cout << "-1\n"; return 0; }
        int k = (b[i] - a[i]) / (b[l] + b[r]);
        ans += k;
        b[i] -= k * (b[l] + b[r]);
        if (a[i] < b[i]) pq.push({b[i], i});
    }
    cout << ans << endl;
}
