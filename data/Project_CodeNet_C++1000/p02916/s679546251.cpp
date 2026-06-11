// https://atcoder.jp/contests/abc140/tasks/abc140_b
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
    vector<int> A(N), B(N), C(N);
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }
    REP(i, N) { cin >> B[i]; }
    REP(i, N - 1) { cin >> C[i]; }
    int ans = 0, before = -2;
    REP(i, N) {
        ans += B[A[i]];
        if (before + 1 == A[i]) {
            ans += C[before];
        }
        before = A[i];
    }
    cout << ans << endl;

    return 0;
}
