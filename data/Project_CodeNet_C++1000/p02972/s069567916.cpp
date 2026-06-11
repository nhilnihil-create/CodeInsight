// 6/26 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> B(N, 0);  // ボールを入れるかどうか。0/1。

    // 後ろから貪欲に決めていく。
    for (int i = N-1; i >= 0; i--) {
        int now = 0;
        for (int j = 2*i+1; j < N; j += (i+1)) now += B[j];
        B[i] = (A[i] - now) % 2;
    }

    // cout << "here?" << endl;

    // int res = 0;
    // for (auto b : B) res += b;
    // cout << res << endl;
    // if (res > 0) rep(i, N) if (B[i] == 1) cout << i + 1 << endl;
    vector<int> ans;
    rep(i, N) if (B[i]) ans.push_back(i);
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        if (i != 0) cout << " ";
        cout << ans[i] + 1 << endl;
    }
}