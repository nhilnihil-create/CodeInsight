#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    priority_queue<int> pq;
    rep(i, n) {
        cin >> a[i];
        pq.push(a[i]);
    }
    rep(i, m) {
        int x = pq.top();
        pq.pop();
        x /= 2;
        pq.push(x);
    }
    ll sum = 0;
    rep(i, n) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
}