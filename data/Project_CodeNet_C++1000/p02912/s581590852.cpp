#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    //take the most expensive and halve it
    for (int i = 0; i < m; i++) {
        int val = pq.top();
        pq.pop();
        pq.push(val / 2);
    }
    ll sum = 0;
    //remove all in pq and sum them
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}