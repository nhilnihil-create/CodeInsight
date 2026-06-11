#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , m;
    cin >> n >> m;

    priority_queue<int> pq;
    for (int i = 0 ;i < n ;i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (m--) {
        int t = pq.top();
        pq.pop();
        pq.push(t / 2);
    }

    long long ans = 0;
    while (pq.size()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}
