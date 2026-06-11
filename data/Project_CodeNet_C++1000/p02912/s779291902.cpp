// 6/30 解き直し
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    priority_queue<int> q;
    rep(i, N) q.push(A[i]);

    while (M--) {
        int p = q.top();
        q.pop();
        q.push(p/2);
    }

    ll res = 0;
    while (!q.empty()) {
        res += q.top();
        q.pop();
    }

    cout << res << endl;
    return 0;
}