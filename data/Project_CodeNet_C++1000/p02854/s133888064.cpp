// https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) {
        cin >> x;
    }
    int sum = accumulate(ALL(A), 0LL);
    int ans = 1e10, t = 0;
    REP(i, N) {
        t += A[i];
        ans = min(ans, abs(sum - 2 * t));
    }
    cout << ans << endl;
    return 0;
}
