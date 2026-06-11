#include <bits/stdc++.h>

using namespace std;

using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int INF = 1<<30;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    llong k;
    cin >> n >> m >> k;
    vector<llong> A(n + 1), B(m), cumB(m + 1);
    A[0] = 0;
    cumB[0] = 0;
    rep(i, n) cin >> A[i + 1];
    rep(i, m) {
        cin >> B[i];
        cumB[i + 1] = cumB[i] + B[i];
    }

    // rep(i, m + 1) cout << cumB[i] << ' ';
    // cout << endl;

    int ans = 0;
    llong t = 0;
    rep(i, n + 1) {
        t += A[i];
        // cout << A[i] << ' ' << k - t << ' ' << lower_bound(all(cumB), k - t) - cumB.begin() << endl;
        if (t > k) continue;
        ans = max(ans, static_cast<int>(upper_bound(all(cumB), k - t) - cumB.begin()) - 1 + i);
        // cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}