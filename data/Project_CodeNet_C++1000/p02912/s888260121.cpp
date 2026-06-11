#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    priority_queue<ll> pq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    while (m) {
        ll top = pq.top();
        pq.pop();

        top = top / 2;
        m--;

        pq.push(top);
    }

    ll ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}