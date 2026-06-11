// 6/30 解き直し
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;

    // vector<int> A(N), B(N);
    // rep(i, N) cin >> A[i] >> B[i];
    // vector<P> J(N);
    vector<P> J;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        // J[i] = P(a, b);
        // cout << a << ", " << b << endl;
        J.push_back({a, b});
    }
    // rep(i, N) printf("J[%d] = %d, %d\n", i, J[i].first, J[i].second);
    sort(J.begin(), J.end());

    int res = 0;
    priority_queue<int> q;
    int id = 0;

    rep(i, M) {
        // M-1日後から決めていく。

        // a[i] <= i + 1の仕事のb[i]をqに追加する。
        while (J[id].first <= i+1) {
            q.push(J[id].second);
            id++;
            if (id>=N) break;
        }

        // キューに要素があれば追加する。
        if (!q.empty()) {
            res += q.top();
            q.pop();
        }
    }

    cout << res << endl;
    return 0;
}