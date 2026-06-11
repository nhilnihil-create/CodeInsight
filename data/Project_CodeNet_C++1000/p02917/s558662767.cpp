// https://atcoder.jp/contests/abc140/tasks/abc140_c
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
    int N, sum = 0;
    cin >> N;
    vector<int> B(N - 1);
    REP(i, N - 1) { cin >> B[i]; }
    REP(i, N - 1) {
        if (i == 0) {
            sum += B[0];
        } else {
            sum += min(B[i - 1], B[i]);
        }
    }
    sum += B[N - 2];
    cout << sum << endl;

    return 0;
}
