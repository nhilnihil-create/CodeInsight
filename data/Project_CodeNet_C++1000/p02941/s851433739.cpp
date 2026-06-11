#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N;
    ll ans = 0;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    priority_queue<vector<int>> q;
    rep(i, N) {
        cin >> B[i];
        q.push({B[i], i});
    }
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (t[0] <= A[t[1]]) continue;
        int d = B[(t[1] - 1 + N) % N] + B[(t[1] + 1) % N];
        int r = (t[0] - max(A[t[1]], d) + d - 1) / d;
        t[0] -= d * r;
        ans += r;
        if (t[0] < A[t[1]] || r == 0) {
            cout << -1 << endl;
            return 0;
        }
        if (t[0] > A[t[1]]) {
            q.push({t[0], t[1]});
        }
        B[t[1]] = t[0];
    }
    rep(i, N) {
        if (A[i] != B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    /*
    9817 1108 6890 4343 8704
    0005
                        4356
              1439
                        0008
                    2896
                    1449
                       2
               329
          774
          440
          106
               221
               113
                5
           96
           86
           76
           66
           56
           46
           36
           26
           16
            6
                            1
    */
}