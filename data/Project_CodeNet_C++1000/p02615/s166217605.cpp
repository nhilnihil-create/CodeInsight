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

    int n;
    cin >> n;
    vector<llong> A(n);
    rep(i, n) cin >> A[i];

    sort(all(A), greater<llong>());
    llong ans = A[0];
    for (int i = 1; i < n - 1; ++i) ans += A[ceil(static_cast<double>(i)/2)];

    cout << ans << endl;

    return 0;
}