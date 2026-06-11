// https://atcoder.jp/contests/abc133/tasks/abc133_c
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
    int L, R;
    cin >> L >> R;
    int ans = 1e15;
    FOR(i, L, min(R + 1, L + 2020)) {
        FOR(j, i + 1, min(R + 1, L + 2020)) {
            // 2019でループし、0は含めると最小になる
            ans = min(ans, (i * j) % 2019);
        }
    }
    cout << ans << endl;

    return 0;
}
